class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum=0,leftsum=0,rightsum=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }

        for(int i=0;i<n;i++)
        {
            rightsum = sum-leftsum-nums[i];
            if(rightsum==leftsum) return i;
            leftsum += nums[i]; 
        }
        return -1;
    }
};