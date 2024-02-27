class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size(),m=mat[0].size();

         int low=0,high=n*m-1,mid,row,col;

         while(low<=high)

         {

             mid=(low+high)/2;

             row=mid/m; // getting the row number

             col=mid%m; // getting the column number

             if(mat[row][col]==target) return true;

             else if(mat[row][col]>target) high=mid-1;

             else low= mid+1;

 

         }

         return false;
    }
};