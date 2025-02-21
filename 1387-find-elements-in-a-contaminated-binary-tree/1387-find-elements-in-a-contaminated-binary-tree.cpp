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
class FindElements {
public:
    unordered_set<int>st;
    void helper(TreeNode* root, int nodeval){

        if(!root) return;
        root->val = nodeval;
        st.insert(root->val);
        if(root->left)  helper(root->left, nodeval *2 + 1);
        if(root->right) helper(root->right, nodeval *2 + 2);
    
    }

    FindElements(TreeNode* root) {
        // root->val = 0;
        // st.insert(root->val);
        helper(root, 0);
    }
    
    bool find(int target) {

        if(st.find(target) != st.end()){
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */