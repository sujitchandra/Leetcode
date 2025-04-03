class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightSmallest(n);
        vector<int> leftSmallest(n);
        
        leftSmallest[0] = INT_MAX;
        rightSmallest[n - 1] = INT_MAX;
        
          for (int i = 1; i < n; i++) {
            leftSmallest[i] = min(leftSmallest[i - 1], nums[i - 1]);
        }
        
        for (int i = n - 2; i >= 0; i--) {
            rightSmallest[i] = min(rightSmallest[i + 1], nums[i + 1]);
        }
        
        int result = INT_MAX;
        
        for (int j = 1; j < n - 1; j++) {
            if (leftSmallest[j] < nums[j] && rightSmallest[j] < nums[j]) {
                result = min(result, leftSmallest[j] + rightSmallest[j] + nums[j]);
            }
        }
        
        return result != INT_MAX ? result : -1;
    }
};