class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int size = n * n;
        vector<int>freq(size+1, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                freq[grid[i][j]]++;
            }
        }
        int duplicate = -1;
        int missing = -1; 
        for(int i=1; i<=size; i++){
            if(freq[i] == 2){
                duplicate = i;
            }
            else if(freq[i] == 0){
                missing = i;
            }
        }
        return {duplicate , missing};

    }
};