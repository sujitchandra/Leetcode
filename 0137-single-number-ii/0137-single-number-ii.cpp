class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int ones = 0 , twos = 0;
        // for(int num: nums){
        //     ones = (ones ^ num) & ~twos;
        //     twos = (twos ^ num) & ~ones;
        // }
        // return ones;
         unordered_map<int, int> freq; // HashMap to store frequency
        
        // Count occurrences of each number
        for (int num : nums) {
            freq[num]++;
        }
        
        // Find the number that appears exactly once
        for (auto& pair : freq) {
            if (pair.second == 1) {
                return pair.first;
            }
        }
        
        return -1;
    }
};