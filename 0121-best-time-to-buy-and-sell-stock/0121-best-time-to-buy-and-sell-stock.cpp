class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0)
        return 0;
        int min = prices[0];// letting minimum price of stock would be in 0th position 
        int maximum = 0;// letting maximum price is 0 in the initial 
        for(int i=0;i<n;i++)
        {
            if(prices[i]<=min)// checking the condition 
            min = prices[i];
            else
            maximum = max(maximum,prices[i]-min);
        }
        return maximum;
    }
};