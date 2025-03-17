class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans;
        long long xorr = 0;
        for(int i=0; i<N; i++){
            xorr ^= nums[i];
        }
        long long rightmost = (xorr & xorr-1) ^ xorr;
        long long b1 = 0;
        long long b2 = 0;
        for(int i=0; i<N; i++){
            if(nums[i] & rightmost) b1 = b1 ^ nums[i];
            else 
            b2 = b2 ^ nums[i];
            
        }
         ans.push_back(b1);
         ans.push_back(b2);
        // if(ans[0] < ans[1]) { // used for ascending order manner..
        //     swap(ans[0], ans[1]);
        // }
         return ans;
    }
};



// good approach but sc is o(n) here so bitwise is efficient memory wise..
// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         unordered_map<int, int> freq; // HashMap to store frequency
//         vector<int> result;

//         // Count occurrences of each number
//         for (int num : nums) {
//             freq[num]++;
//         }

//         // Find the two numbers that appear exactly once
//         for (auto& pair : freq) {
//             if (pair.second == 1) {
//                 result.push_back(pair.first);
//             }
//         }

//         return result;
//     }
// };