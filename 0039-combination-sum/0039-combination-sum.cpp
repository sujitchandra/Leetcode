class Solution {
public:
    
    void help(int ind, vector<int>& arr, int target, vector<int>& ds, vector<vector<int>>& ans){
        
        if(ind == arr.size()){
            if(target == 0)
                ans.push_back(ds);
            return;
        }
        
        // pick
        
        if(target >= arr[ind] ) {
            ds.push_back(arr[ind]);
            help(ind, arr, target - arr[ind], ds, ans);
            ds.pop_back();
        }
        
        // non-pick
        
        help(ind + 1, arr, target, ds, ans);
    }    
    

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        help(0, candidates, target, ds, ans);
        return ans;
    }
};
