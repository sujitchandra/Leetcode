class Solution {
public:
    int firstoccurance(vector<int>& arr, int n, int k){
    int l = 0;
    int h = n-1;
    int first = -1;
    while(l <= h){
        int mid = (l+h)/2;
        if (arr[mid] == k) {
          first = mid;
          h = mid - 1;
        } else if (arr[mid] > k) {
          h = mid - 1;
        } else
          l = mid + 1;
    }
    return first;
}
int secondoccurance(vector<int>& arr, int n, int k){
    int l = 0;
    int h = n-1;
    int last = -1;
    while(l <= h){
        int mid = (l+h)/2;
        if (arr[mid] == k) {
        last = mid;
        l = mid + 1;
        } 
        else if (arr[mid] > k) {
        h = mid - 1;
        }
         else
        l = mid+1;
    }
    return last;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstoccurance(nums, n, target);
         if(first == -1) return {-1,-1};
         int second = secondoccurance(nums, n, target);
         return {first, second};
    }
};