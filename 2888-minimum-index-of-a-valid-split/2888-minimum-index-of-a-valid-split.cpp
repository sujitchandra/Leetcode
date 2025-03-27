class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int count = 0 , major = 0;

        for (int i=0; i<n; i++) {
            if (count == 0) {
                major = nums[i];
            }
            
            if (nums[i] == major) {
                count++;
            } else {
                count--;
            }
            
        }

        int major_cnt = 0;
        for(auto& num: nums){
            if(num == major)
            major_cnt++;
        }

        int left_cnt = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i] == major) left_cnt++;
            int right_cnt = major_cnt - left_cnt;
            if(left_cnt * 2 > (i+1) && right_cnt *2 > (n-i-1)){
                return i;
            }
        }
        return -1;

    }
};