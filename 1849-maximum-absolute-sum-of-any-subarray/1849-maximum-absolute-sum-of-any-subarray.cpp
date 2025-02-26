class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int presum = 0;
        int maxi = 0; 
        int mini = 0;
        int res = 0; //[2,-5,1,-4,3,-2] , maxi = 3 , mini = -2
        for(int i=0; i<n; i++){
            presum += nums[i];
            maxi = max(maxi , presum);
            mini = min(mini , presum);
        }
        res = abs(maxi - mini);
        return res;
    }
};