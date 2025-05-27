class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = n*(n+1)/2;
        int divisiblesum = m* (n/m) * (n/m+1);
        return sum - divisiblesum;
    }
};
