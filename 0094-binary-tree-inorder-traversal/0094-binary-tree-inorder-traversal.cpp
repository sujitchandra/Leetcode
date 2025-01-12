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
    void preorderHelper(TreeNode* root, vector<int>& ino) {
        if (root == nullptr) return;
        
        preorderHelper(root->left, ino); 
        ino.push_back(root->val); 
        preorderHelper(root->right, ino); 
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ino;
        preorderHelper(root, ino); 
        return ino;
    }
};