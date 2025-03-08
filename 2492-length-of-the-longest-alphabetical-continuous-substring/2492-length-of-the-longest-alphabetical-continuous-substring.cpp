class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n =s.length();
        int total = 1 ,maxi = 1;

        for(int i=1; i<n; i++){
            if(s[i] - s[i-1] == 1){
                total++;
            }
            else{
                total = 1;
            }
            maxi = max(maxi , total); 
        }
        return maxi;
        
    }
};