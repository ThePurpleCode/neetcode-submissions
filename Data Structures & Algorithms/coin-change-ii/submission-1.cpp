class Solution {
public:
    int change(int amount, vector<int>& coins) { 
        int n = coins.size();
        vector<unsigned int> dp(amount+1,0); // 1D soln .. dp[i] =tot no of ways for amount i

        dp[0] = 1;

        for(auto coin :coins){
            for(int j = coin;j<=amount;j++){
                dp[j] += dp[j-coin];
            }
        }
        return (int)dp[amount];
    }
};