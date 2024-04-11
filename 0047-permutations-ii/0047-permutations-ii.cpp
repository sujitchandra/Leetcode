class Solution {
public:
    void help(vector<int>& nums, vector<vector<int>>& ans, int ind){
        // base case
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        vector<bool> use(21,0);
        for(int i=ind; i<nums.size(); i++){
            if(use[nums[i] + 10] == 0){
                swap(nums[i], nums[ind]);
                help(nums,ans,ind+1);
                swap(nums[i], nums[ind]);
                use[nums[i]+10] = 1;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        help(nums,ans,0);
        return ans;
    }
};