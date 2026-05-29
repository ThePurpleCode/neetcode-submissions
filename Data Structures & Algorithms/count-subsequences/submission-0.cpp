class Solution {
public:
    int solve(int i , int j ,string& s, string &t,vector<vector<int>>& dp){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;

        if(dp[i][j]!= -1) return dp[i][j];

        int ways =0;
        if(s[i]==t[j]){
            int take = solve(i+1, j+1,s,t,dp);
            int leave = solve(i+1,j,s,t,dp);
            ways = take +leave;
        }
        else{
            ways = solve(i+1,j,s,t,dp);
        }
        dp[i][j] = ways;
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

        return solve(0,0,s,t,dp);
    }
};
