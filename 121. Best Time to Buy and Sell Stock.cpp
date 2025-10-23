class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size(),low_buy_price =INT_MAX,profit=0;

        for(int i=0;i<n;i++)
        {
            if (prices[i] < low_buy_price) low_buy_price = prices[i];
            else profit = max(profit,prices[i]- low_buy_price);
        }
         return profit;
    }
};