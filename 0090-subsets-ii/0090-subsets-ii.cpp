class Solution {
public:
    
    void help( vector<vector<int>>&ans, int index, vector<int>&arr, vector<int>&output)
{
  
    ans.push_back(output);
    for(int j=index; j<arr.size(); j++){

        if(j!=index && arr[j]==arr[j-1]){
            continue;
        }
    output.push_back(arr[j]);
    help(ans, j+1, arr, output);
    output.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>>ans;

    vector<int>output;

   sort(arr.begin(), arr.end());

    help(ans, 0, arr, output);

    return ans;
    }
};