class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans = "";
        int cnt = 0;
        bool flag = true;
        for (int i=0; i<n; i++){
            if(s[i] == '(')
                cnt++;
            else if(s[i] == ')')
                cnt--;
            if(cnt == 1 && flag == true){
                flag = false;
                continue;
            }
            if(cnt == 0 && flag == false){
                flag = true;
                continue;
            }
            ans += s[i];
        }
        return ans;
    }
};