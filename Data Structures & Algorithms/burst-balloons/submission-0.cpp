class Solution {
public:
    int solve(int i , int j , vector<int>& nums ,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mx_coins=0;
        for(int k=i;k<=j;k++){ // make sure k is the last ballon to be burst in range i to j
            int leftk_burst = solve(i,k-1,nums,dp); // ans of bursting i- k-1 baloons left of k
            int rightk_burst = solve(k+1,j,nums,dp);// ans of bursting k+1 j baloons right of k
            int k_burst = nums[k]*nums[i-1]*nums[j+1]; // last ballon in range i to j (inc) is k
            int total_burst = rightk_burst + leftk_burst + k_burst; // total baloons burst in this range
            mx_coins = max(total_burst , mx_coins);
        }
        dp[i][j]=mx_coins;
        return dp[i][j];
    }
    int maxCoins(vector<int>& nums) { // go rerverse .. which baloon will burst last in range i to j
        int n =nums.size();
        vector<int> paded_nums; // paadding 1 on both ends;
        paded_nums.push_back(1);
        for(int num :nums)  paded_nums.push_back(num);
            paded_nums.push_back(1);

        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return solve(1,n,paded_nums,dp);
    }
};