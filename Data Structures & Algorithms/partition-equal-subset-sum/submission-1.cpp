class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x:nums) sum += x;

        if(sum%2!=0) return false;
        int target = sum/2; // we will check do some of the numbers make upto target = sum/2
        vector<bool> dp(target+1 , false); // dp[i] can we make sum upto i from the array given or nums we have seen sofar
        dp[0] = true;

        for(int x:nums){
            for(int i = target;i>=x;i--){
                if(dp[i-x]){
                    dp[i] = true;
                }
            }
        }
        return dp[target];
    }
};