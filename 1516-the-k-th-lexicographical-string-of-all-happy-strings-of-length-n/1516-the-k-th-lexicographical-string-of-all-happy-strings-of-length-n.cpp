class Solution {
public:
int cnt = 0;
    bool helper(int n, int k, string &s)
    {
        if(s.length() == n) {
            // ans.push_back(s);
            cnt++;
            if(cnt == k) return true;
            return false;
        }
        // vector<char> ch = {'a','b','c'};
        for(char i='a'; i<= 'c'; i++){
            if(s.length() == 0 || s.back() != i)
            {
                s.push_back(i);
               if( helper(n,k,s)) return true;
                s.pop_back();
            }
        }
        return false;
    }
    string getHappyString(int n, int k) {
        
        // vector<string> ans;
        string s;
        helper(n,k,s);
        // if(k <= ans.size())
        // return ans[k-1];
        // else
        // return "";
        return s;

    }
};
//[a,b,c] => [ab,bc,ac,ba,cb,ca] of 2 length
// lexicographical order => [ab,ac,ba,bc,ca,cb]
// of 3 length [aba,abc,acb,bab,bac,bca,cab,cba,cac] n=2, k=1 => ? ab :""