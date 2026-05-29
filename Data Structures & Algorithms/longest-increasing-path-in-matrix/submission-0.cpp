class Solution {
public:
    int dirx[4] = {1,-1,0,0};
    int diry[4] = {0,0,1,-1};

    int dfs(int r , int c ,vector<vector<int>>& matrix, vector<vector<int>>& dp){
        int m = matrix.size();
        int n = matrix[0].size();
        int mx_path =1;

        if(dp[r][c]!=0) return dp[r][c];

        for(int k=0;k<4;k++){
            int nr = r + dirx[k];
            int nc = c + diry[k];

            if(nr>=0 && nr<m && nc>=0 && nc<n && matrix[nr][nc]>matrix[r][c]){
                int path = 1 +dfs(nr , nc , matrix , dp);
                mx_path = max(path , mx_path);
            }
        }
        dp[r][c] = mx_path;
        return dp[r][c];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n,0));

        int ans =0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                ans = max(ans , dfs(r,c,matrix,dp));
            }
        }
        return ans;

    }   
};
