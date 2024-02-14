class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int pref =1 ,suff =1;
        for(int i=0; i<nums.size(); i++){
            if(pref == 0) pref = 1;
            if(suff == 0) suff = 1;
            pref = pref * nums[i];
            suff = suff * nums[n-i-1];
            maxi = max( maxi, max(pref,suff));
            }
        return maxi;
    }
};