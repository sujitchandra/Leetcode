class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int cnt = 0;
        int validcnt = 1;

        for(int i=0; i<n+k-2; i++){

            if(colors[(i+1)%n] != colors[i%n]) validcnt++;
            else {
                validcnt = 1;
            }

            if(validcnt >= k) cnt++;

        }
        
        return cnt;
    }
};