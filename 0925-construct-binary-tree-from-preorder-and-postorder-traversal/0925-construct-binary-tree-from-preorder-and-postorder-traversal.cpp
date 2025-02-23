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
    TreeNode* helper(vector<int>&preorder, vector<int>&postorder, unordered_map<int, int> &post, 
    int &preorderindex, int start, int end)
    {
        if(start > end) return nullptr;

        TreeNode* root = new TreeNode (preorder[preorderindex]);
        preorderindex++;

    //  if (!root) return nullptr;
        if(start == end) return root;


        int last = post[preorder[preorderindex]];
        if(last <= end){
        root->left = helper(preorder, postorder, post, preorderindex, start , last);
        root->right = helper(preorder, postorder,post, preorderindex, last + 1, end-1);
        }

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = postorder.size();
        int preorderindex = 0;
        unordered_map<int, int> post;
        for(int i=0; i<n; i++){
            post[postorder[i]] = i;
        }
         return helper(preorder, postorder, post, preorderindex, 0 , n-1);
    }
};
// TC=> O(N), SC=> O(N)