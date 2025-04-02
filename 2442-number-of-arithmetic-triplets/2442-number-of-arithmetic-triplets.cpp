// class Solution {
// public:
//     int arithmeticTriplets(vector<int>& nums, int diff) {
//          int n = nums.size();
//         int cnt = 0;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 for(int k=j+1; k<n; k++){
//                     if((nums[j] - nums[i] == diff) && (nums[k] - nums[j] == diff)) cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int counter = 0;
        unordered_set <int> numSet (nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            if (numSet.count(nums[i] + diff) && numSet.count(nums[i] + (2*diff))){
                counter ++;
            }
        }
        return counter;
    }
};