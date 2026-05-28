class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned int>> dp(n+1,vector<unsigned int>(amount+1,0)); // dp[i][j] = ways to have j amount with first i coins

        for(int i=0;i<=n;i++) dp[i][0] =1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                dp[i][j] = dp[i-1][j]; // A. dont pick this ith coin

                if(j-coins[i-1]>=0){
                    dp[i][j] += dp[i][j-coins[i-1]]; // B. pick this ith coin which is on i-1th index of coins 
                }
            }
        }
        return (int)dp[n][amount];
    }
};
