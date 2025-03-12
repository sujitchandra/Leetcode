class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int pos = 0, neg = 0;
        int maxi = 0;
        for(int num : nums){
            if(num > 0) pos++;
            else if (num < 0) neg++;
             maxi = max(maxi , max(pos, neg));
        }
        return maxi;
    }
};