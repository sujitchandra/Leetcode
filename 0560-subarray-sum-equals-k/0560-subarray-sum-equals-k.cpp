class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m={};
        int n = nums.size();
        int presum = 0;
        int cnt= 0;
        m[0] = 1; // means 0 has occured one times..
        for(int i=0;i<n;i++)
        {
            presum = presum + nums[i];
            cnt = cnt + m[presum-k];
            m[presum]++;
        }
        return cnt;
    }
};
