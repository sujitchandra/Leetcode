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

    void posorderHelper(TreeNode* root, vector<int>& pos) {
        if (root == nullptr) return;
        
        posorderHelper(root->left, pos); 
        posorderHelper(root->right, pos);
        pos.push_back(root->val); 
 
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>pos;
        posorderHelper(root, pos); 
        return pos;
    }
};