class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        int count = 1;
        // Sort intervals by their end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int lastend = intervals[0][1];

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= lastend) {
                count++;
                lastend = intervals[i][1];
            }
        }

        return n - count; // Number of intervals to remove
    }
};