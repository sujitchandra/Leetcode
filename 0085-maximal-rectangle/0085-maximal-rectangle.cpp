class Solution {
public:
// int maxhisto(vector<int>& heights) {
//         stack < int > st;
//          int maxA = 0;
//         int n = heights.size();
//         for (int i = 0; i <= n; i++) {
//             while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
//             int height = heights[st.top()];
//             st.pop();
//             int width;
//             if (st.empty())
//              width = i;
//              else
//                 width = i - st.top() - 1; // nse-pse-1 says 
//             maxA = max(maxA, width * height);
//             }
//          st.push(i);
//         }
//         return maxA;
//     }

//     int maximalRectangle(vector<vector<char>>& matrix) {
//         int maxarea = 0;
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<vector<int>> presum;
//         for(int j=0; j<n; j++){
//             int sum = 0;
//             for(int i=0; i<m; i++){
//                  sum += matrix[i][j];
//                 if(matrix[i][j] == 0) sum =0;
//                 presum[i][j] = sum;
//             }
//         }
//         for(int i=0; i<n; i++){
//             maxarea = max(maxarea, maxhisto(presum[i]));
//         }
//         return maxarea;
//     }
// };
int maxInHistogram(vector<int>& arr) {
        int n=arr.size();
        int maxi=0;
        stack<int> st;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || arr[st.top()]>=arr[i])){
                int height=arr[st.top()];
                st.pop();
                int width;
                if(st.empty())  width=i;
                else     width=i-st.top()-1;
                maxi=max(maxi,(height*width));
            }
            st.push(i);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int r=mat.size();
        if(r==0) return 0;
        int c=mat[0].size();
        int maxi=0;
        vector<int> histo(c,0);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]=='1')    histo[j]+=1;
                else    histo[j]=0;
            }
            maxi=max(maxi,maxInHistogram(histo));
        }
        return maxi;
    }
};