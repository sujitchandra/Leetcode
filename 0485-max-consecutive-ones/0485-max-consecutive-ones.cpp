class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int n = nums.size();
        int count = 0;
        int maximum = 0;
        for (int i=0; i<n; i++){
            if(nums[i] != 1)
                count = 0;
            else
                count++;
            maximum = max (maximum , count);
        }
        return maximum;
    }
};