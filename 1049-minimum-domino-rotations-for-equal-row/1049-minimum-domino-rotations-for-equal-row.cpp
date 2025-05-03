//cp
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX;
        for(int val=1; val<=6; val++){
            int Swap1=0, Swap2=0;

            for(int i=0;i<tops.size();i++){
                if(tops[i]!=val && bottoms[i]!=val){
                    Swap1=INT_MAX;
                    Swap2=INT_MAX; 
                    break;
                }

                if(tops[i]!=val){Swap1++;}
                if(bottoms[i]!=val){Swap2++;}
            }

            ans = min(ans, min(Swap1,Swap2));
        }

        return ans==INT_MAX?-1:ans;
    }
};