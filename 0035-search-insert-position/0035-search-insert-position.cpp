class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int start = 0;
    int end = n - 1;
    int ans = n; 
    while (start <= end) {
        int mid = (start + end) / 2;
        if (nums[mid] == target) {
          return mid;
        } else if (nums[mid] < target) {
          start = mid + 1;
        } else {
          ans = mid;
          end = mid - 1;
        }
    }

    return ans; 
    }
};