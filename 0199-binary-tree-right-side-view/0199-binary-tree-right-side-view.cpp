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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans; 
        if (!root) return ans;

        queue<TreeNode*> q; // Queue for level-order traversal
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int lastValue; // To store the last value at the current level

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                lastValue = node->val; // Update the last value at this level

                // Add left and right children to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(lastValue); 
        }

        return ans;
    }
};
