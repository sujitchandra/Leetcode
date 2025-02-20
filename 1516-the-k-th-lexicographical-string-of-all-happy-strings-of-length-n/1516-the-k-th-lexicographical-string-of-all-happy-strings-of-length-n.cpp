class Solution {
public:
    void helper(int n, int k, string s, vector<string>&ans)
    {
        if(s.length() == n) {
            ans.push_back(s);
            return;
        }
        vector<char> ch = {'a','b','c'};
        for(int i=0; i<3; i++){
            if(s.length() == 0 || s.back() != ch[i] )
            {
                s.push_back(ch[i]);
                helper(n,k,s,ans);
                s.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        
        vector<string> ans;
        string s;
        helper(n,k,s,ans);
        if(k <= ans.size())
        return ans[k-1];
        else
        return "";

    }
};
//[a,b,c] => [ab,bc,ac,ba,cb,ca] of 2 length
// lexicographical order => [ab,ac,ba,bc,ca,cb]
// of 3 length [aba,abc,acb,bab,bac,bca,cab,cba,cac] n=2, k=1 => ? ab :""