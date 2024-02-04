class Solution {
public:
     vector<int>sortColors(vector<int>& nums) {
        int y = 0;
        int n = nums.size();
        // placing 0 to the starting order
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                swap(nums[i],nums[y]);
                y++;
            }
        }
        int k = n-1;
        // placing all 2 in the end of the array
        for(int i=k; i>=0; i--)
        {
            if(nums[i]==2)
            {
                swap(nums[i],nums[k]);
                k--;
            }
        }
        return nums;
        
    }
};