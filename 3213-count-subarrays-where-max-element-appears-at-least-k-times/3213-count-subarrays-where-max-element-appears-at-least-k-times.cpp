class Solution {
public:
        long long countSubarrays(vector<int>& nums, int k, int left = 0) {
        long maxi = *max_element(nums.begin(), nums.end());
        long maxiOccurence = 0;
        long cnt = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == maxi) {
                ++maxiOccurence;
            }
            while (maxiOccurence >= k) {
                if (nums[left] == maxi) {
                    --maxiOccurence;
                }
                left++;
            }
            cnt += left;
        }
        return cnt;
    }
};