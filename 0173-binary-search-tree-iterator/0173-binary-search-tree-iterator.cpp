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
class BSTIterator {
public:
        BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    int next() {
        TreeNode* node = stack.top();
        stack.pop();
        pushall(node->right); 
        return node->val;
    }
    
    bool hasNext() {
        return !stack.empty();
    }

private:
    stack<TreeNode*> stack;
  
    void pushall(TreeNode* root) {
        while (root != nullptr) {
            stack.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */