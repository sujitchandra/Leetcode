class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string max_good = "";
        for (int i=0; i+2<n; i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                max_good = max(max_good, num.substr(i, 3));
            }
        }
        return max_good;
    }
};
