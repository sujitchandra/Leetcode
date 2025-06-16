class Solution 
{
public:
    int maximumDifference(vector<int>& nums) 
    {
        int n = nums.size();
        int mini = nums[0];  
        int diff = -1;

        for (int i=1; i<n; i++) 
        {  
            if (nums[i] > mini) 
            {
                diff = max(diff, nums[i] - mini);
            } 
            else 
            {
                mini = nums[i];
            }
        }

        return diff;  
    }
};