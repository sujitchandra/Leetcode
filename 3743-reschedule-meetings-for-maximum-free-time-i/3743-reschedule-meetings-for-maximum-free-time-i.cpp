//cp
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size();
        int ans = 0, curr = 0;

        for (int i = 0; i <= n; ++i) {
            if (i == 0)
                curr += startTime[0];
            else if (i == n)
                curr += (eventTime - endTime[n - 1]);
            else
                curr += (startTime[i] - endTime[i - 1]);
            if (i >= k + 1) {
                if (i - (k + 1) == 0)
                    curr -= startTime[0];
                else if (i - (k + 1) == n)
                    curr -= (eventTime - endTime[n - 1]);
                else
                    curr -= (startTime[i - (k + 1)] - endTime[i - (k + 1) - 1]);
            }

            ans = max(ans, curr);
        }
        return ans;
    }
};