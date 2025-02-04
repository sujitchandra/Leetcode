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
    
//    void preorderHelper(TreeNode* root, vector<int>& pre) {
//     if (root == nullptr) return;

//     pre.push_back(root->val); 
//     preorderHelper(root->left, pre); 
//     preorderHelper(root->right, pre); 
// }

vector<int> preorderTraversal(TreeNode* root) {
    // vector<int> pre;
    // preorderHelper(root, pre); 
    // return pre;
    vector<int> inorder;
        TreeNode* cur = root;
        while(cur != NULL)
        {
            if(cur->left == NULL){
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* prev = cur->left;
                while(prev->right && prev->right != cur){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = cur;
                    inorder.push_back(cur->val);
                    cur = cur->left;
                }
                else{
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return inorder;
}

};