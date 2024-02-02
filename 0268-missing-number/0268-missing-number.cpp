class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
		int missing = 0;
        int sum = 0;
        int current = n*(n+1)/2;
        for (int i=0; i<n; i++){
            sum = sum + nums[i];
        }
        missing = current - sum;
        return missing;
        
    }
};