class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_ele_rn = prices[0], max_profit=0;
        for(int i=0;i<prices.size();i++){
            min_ele_rn = min(prices[i],min_ele_rn);
            max_profit = max(prices[i]-min_ele_rn , max_profit);
        }
        return max_profit;
    }
};