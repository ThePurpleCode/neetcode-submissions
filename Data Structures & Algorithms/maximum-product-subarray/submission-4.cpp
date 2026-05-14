class Solution {
public:
    int solve(vector<int>& nums,vector<int>& maxdp, vector<int>& mindp ,int i){
        if(i==0){
            maxdp[0] = nums[0];
            mindp[0] = nums[0];
            return maxdp[0];
        }
        if(maxdp[i]!=INT_MIN) return maxdp[i];

        solve(nums,maxdp,mindp,i-1);

        maxdp[i] = max(nums[i],(max(maxdp[i-1]*nums[i], mindp[i-1]*nums[i])));
        mindp[i] = min(nums[i] ,(min(mindp[i-1]*nums[i],maxdp[i-1]*nums[i]))); // 3 possibilities
        //1.start new subarray
        // extend both max and min array

        return maxdp[i];

    }
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxdp(n,INT_MIN);
        vector<int> mindp(n,INT_MIN);

        int ans = nums[0];
        for(int i=0;i<nums.size();i++)
        ans = max(ans , solve(nums,maxdp,mindp,i));
        
        return ans;
    }
};