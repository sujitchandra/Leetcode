class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        
        // Find the index to perform the swap
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            // If no index is found, reverse the array
            reverse(nums.begin(), nums.end());
        } else {
            // Find the element to swap with
            for (int i = n - 1; i > index; i--) {
                if (nums[i] > nums[index]) {
                    swap(nums[i], nums[index]);
                    break;
                }
            }

            // Reverse the subarray to get the next permutation
            reverse(nums.begin() + index + 1, nums.end());
        }
        
    }
};