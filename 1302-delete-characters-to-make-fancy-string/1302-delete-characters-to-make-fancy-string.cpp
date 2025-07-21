//cp but understood
class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string ans;
        char last = s[0];
        ans.push_back(last);
        int cnt = 1;
        for (int i=1; i<n; i++) {
            if (s[i] == last) {
                cnt++;
                if (cnt < 3)
                    ans.push_back(s[i]);
            } else {
                last = s[i];
                cnt = 1;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
