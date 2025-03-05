class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1 + 4LL * n *(n-1) /2;
        return ans;
    }
};