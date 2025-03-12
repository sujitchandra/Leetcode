class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for(int i=0; i<m; i++){
            int st = 0 , end = n-1;
            while(st <= end){
                int mid = st + (end -st)/2;
                if(grid[i][mid] >= 0){
                    st = mid + 1;
                }
                else {
                    end  = mid - 1;
                }
                
            }
            cnt += n -st;
        }
        return cnt;
    }
};