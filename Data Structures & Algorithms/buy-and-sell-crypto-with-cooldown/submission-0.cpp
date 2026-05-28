class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(n,0); // max profit for holding stock .. 1. buy prev or buy on this day
        vector<int> sell(n,0); // max profit if we are holding this stock or selling it on i
        vector<int> cool(n,0); // max profit if we are resting on this i

        buy[0] = -prices[0]; // at first day or 0th index if we buy the stock our purse has -of 0th index stock price
        for(int i=1;i<n;i++){
            buy[i] = max(buy[i-1] , (cool[i-1]-prices[i])); // purana buyed , sold->last ka cooldown - today ka price
            sell[i] = buy[i-1] + prices[i]; // i-1 pe stock tha abhi sell kia
            cool[i] = max(sell[i-1] , cool[i-1]); // kl sell kia ya kl rest kia and aaj buy nhi kia
        }
        int ans = max(cool[n-1],sell[n-1]);
        return ans;
    }
};