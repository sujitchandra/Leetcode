class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int right = n-1;
        int total = 0;

        for(int i=0; i<k; i++){
            total += cardPoints[i];
        }
        int maximum = total;

        for(int i = k-1; i >= 0; i--){
            total = total - cardPoints[i] + cardPoints[right];
            right--;
            maximum = max(maximum , total);
        }
        return maximum;
    }
};