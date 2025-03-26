class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>store;
        int op = 0;

        for(int i=0;i<m;i++){
            for(int j=0; j<n; j++){
                store.push_back(grid[i][j]);
            }
        }

        sort(store.begin(), store.end());
        int middle = store[store.size()/2];

        for(auto& num:store){
            if((num - middle)% x != 0) return -1;
            op += abs(num-middle)/x;
        }
        return op;



        // for(int i=0; i<store.size(); i++){
        //     cout << store[i];
        // }
        // return 0;
    }
};