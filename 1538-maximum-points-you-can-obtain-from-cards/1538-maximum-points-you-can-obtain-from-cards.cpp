class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int rightsum = 0;
        int right = n-1;
        int total = 0 , maxtotal = 0;

        for(int i=0; i<k; i++){
            total += cardPoints[i];
        }
        int maximum = total;

        for(int i = k-1; i >= 0; i--){

            total -=  cardPoints[i];
            rightsum += cardPoints[right];
            maxtotal = total + rightsum;
            right--;
            maximum = max(maximum , maxtotal);
        }
        return maximum;
    }
};