class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int cnt1 = 0, cnt2 = 0;
        long long sum1 = 0, sum2 = 0;
        for(auto i : nums1){
            sum1 += i;
            if(i == 0){
                sum1 += 1;
                cnt1++;
            }
        }

        for(auto j : nums2){
             sum2 += j;
            if(j == 0){
                sum2 += 1;
                cnt2++;
            }
        }
        if((cnt1 == 0 && sum2 > sum1) || (cnt2 == 0 && sum1 > sum2)) return -1;
        return max(sum1 , sum2);
    }
};