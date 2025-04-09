class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int num : nums){
            if(num < k){
                return -1;
            }
            mp[num]++;
        }
        mp[k]++;
        return mp.size()-1;
    }
};