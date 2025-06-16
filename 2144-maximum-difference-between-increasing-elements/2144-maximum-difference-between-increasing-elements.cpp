class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                cnt = max(cnt , (nums[j] - nums[i]));
            }
        }
        return (cnt <= 0)? -1 : cnt;
    }
};