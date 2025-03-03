class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans;
        // int cnt = 0;
        // for the smaller than pivot case

        for(int i=0; i<n; i++){
            if(nums[i] < pivot){
                ans.push_back(nums[i]);
            }
        }
        // for the case pivot == nums[i]
        for(int i=0; i<n; i++){
            if(nums[i] == pivot) {
                ans.push_back(nums[i]);
            }
        }

        // while(cnt != 0){
        //     ans.push_back(pivot);
        //     cnt--;
        // }
        
        // for the larger than pivot case 

        for(int i=0; i<n; i++){
            if(nums[i] > pivot){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};