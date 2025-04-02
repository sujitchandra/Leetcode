class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return -1;
        
        vector<int> leftMin(n, INT_MAX);
        vector<int> rightMin(n, INT_MAX);

        leftMin[0] = nums[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i - 1], nums[i]);
        }

        rightMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = min(rightMin[i + 1], nums[i]);
        }

        int mini = INT_MAX;

        for (int j = 1; j < n - 1; j++) {
            if (leftMin[j - 1] < nums[j] && rightMin[j + 1] < nums[j]) {
                mini = min(mini, leftMin[j - 1] + nums[j] + rightMin[j + 1]);
            }
        }

        return (mini == INT_MAX) ? -1 : mini;
    }
};
