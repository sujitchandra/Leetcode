class Solution {
public:
    void help(int n, int left, int right, vector<string>& ans, string &temp)
    {
        if ((right + left) == 2 * n) {
            ans.push_back(temp);
            return;
        }
        // for left
        if (left < n) {
            temp.push_back('(');
            help(n, left + 1, right, ans, temp);
            temp.pop_back();
        }
        
        // for right
        if (right < left) {
            temp.push_back(')');
            help(n, left, right + 1, ans, temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        int left = 0, right = 0; // Initially left and right is 0
        help(n, left, right, ans, temp);
        return ans;
    }
};