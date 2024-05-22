class Solution {
public:
    vector<vector<int>> ans;
    
    void help(vector<int>& nums, int index, int n , vector<int>& temp){
        if(index == n)
        {
            ans.push_back(temp);
            return;
        }
        
        help(nums, index + 1, n, temp); // for no case 
        
        temp.push_back(nums[index]); // store in temp for yes case 
        help(nums, index + 1, n, temp); // for yes case
        
       temp.pop_back(); // backtracking and for optimal space usage
    } 
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> temp;
        help(nums, 0, n, temp);
        return ans;
    }
};