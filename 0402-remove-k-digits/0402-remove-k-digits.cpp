class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i = 0; i < num.size(); i++) {
            while(!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        // Remove remaining k digits from the end
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        // If stack is empty, return "0"
        if(st.empty()) return "0";
        

        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        // Reverse the result..
        reverse(res.begin(), res.end());
        // Remove leading zeros
        while(res.size() > 1 && res[0] == '0') {
            res.erase(res.begin());
        }
        return res;
    }
};