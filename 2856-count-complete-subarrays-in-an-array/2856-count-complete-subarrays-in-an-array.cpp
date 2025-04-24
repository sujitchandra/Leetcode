class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end()); 
        int size_of_set= st.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            int distcount = 0;

            for (int j = i; j < n; j++) {
                if (++mp[nums[j]] == 1) {
                    distcount++;
                }

                if (distcount == size_of_set) {
                    count++;
                }
            }
        }

        return count;
    }
};
