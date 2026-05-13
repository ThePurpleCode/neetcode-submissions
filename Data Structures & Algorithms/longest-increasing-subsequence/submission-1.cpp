class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int mx=1;

        vector<int> dp(n, 1); // dp[i] stores max subseq till it(including it); ini at 1 coz if not any prev it is 1 (that number , nums[i])
        dp[0] = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[j]+1 , dp[i]);
                }
                mx = max(dp[i],mx);
            }
        }
        return mx;
    }
};