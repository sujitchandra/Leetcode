class Solution {
public:
   static bool customComparator(int a, int b, unordered_map<int, int>& freq) {
        if (freq[a] == freq[b]) 
            return a > b;  
        return freq[a] < freq[b]; 
    }

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return customComparator(a, b, freq);
        });

        return nums;
    }
};