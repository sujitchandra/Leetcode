class Solution {
public:
    int helper(int i, int j, string &text1, string &text2,vector<vector<int>> &dp ){

        int n = text1.size();
        int m = text2.size(); 
        if(i >= n || j >= m) return 0;

        if(dp[i][j] != -1 ) return dp[i][j];
        if(text1[i] == text2[j]){
          return dp[i][j] =  (1 + helper(i+1, j+1, text1, text2, dp));
        }  
        else{
          return dp[i][j] =  max(helper(i+1,j,text1,text2,dp) , helper(i, j +1, text1, text2,dp));
            
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
         int n = text1.size();
         int m = text2.size();
        vector<vector<int>> dp;
        dp.assign(n, vector<int>(m,-1));

        return helper(0,0,text1, text2,dp);
       
    }
};