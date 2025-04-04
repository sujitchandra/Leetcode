/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*> parent;
        q.push(root);
        vector<TreeNode*> deepest;

        // Level-order traversal to find deepest nodes
        while (!q.empty()) {
            int size = q.size();
            deepest.clear(); // clear for the current level
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                deepest.push_back(node);
                if (node->left) {
                    q.push(node->left);
                    parent[node->left] = node;
                }
                if (node->right) {
                    q.push(node->right);
                    parent[node->right] = node;
                }
            }
        }

        // If only one deepest node, return it
        if (deepest.size() == 1) return deepest[0];

        // Find LCA of all deepest nodes using pairwise reduction
        TreeNode* lca = deepest[0];
        for (int i = 1; i < deepest.size(); ++i) {
            lca = findLCA(root, lca, deepest[i]);
        }

        return lca;
    }

private:
    // Standard LCA finder in binary tree (not BST)
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = findLCA(root->left, p, q);
        TreeNode* right = findLCA(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
};
