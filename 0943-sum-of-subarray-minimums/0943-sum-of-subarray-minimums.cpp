class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int mod = 1e9 + 7;
        int ans = 0, n = arr.size();
        vector<int> nse(n), pse(n);
        stack<int> st;

        // Finding next smaller elements (NSE)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            nse[st.top()] = n;
            st.pop();
        }

        // Finding previous smaller elements (PSE)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            pse[st.top()] = -1;
            st.pop();
        }

        // Calculating the sum of subarray minimums
        for (long i = 0; i < n; i++) {
            ans = (ans + (long long)(i - pse[i]) * (nse[i] - i) * arr[i]) % mod;
        }

        return ans;
    }
};
