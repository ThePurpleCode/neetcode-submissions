class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int tot_sum =0;
        for(auto num :nums) tot_sum +=num;

        int final_target = (target + tot_sum)/2;
        if(abs(target)>tot_sum) return 0;
        if((target + tot_sum)%2==1) return 0;

        // now it is coin  change 2 ques as it is amount is final_target
        vector<int> dp(final_target +1 , 0);
        dp[0] =1;

        for(auto x:nums){
            for(int j=final_target;j>=x;j--){ // revrse due to we can pick no only once but in coin change II we have infinite coins
                dp[j] += dp[j-x];
            }
        }
        return dp[final_target];
    }
};