class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ct=0;
        int n = nums.size();

        vector<int> prefix_sum(n+1,0);
        for(int i=1;i<=n;i++){
            prefix_sum[i] = prefix_sum[i-1] + nums[i-1];
        }

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(prefix_sum[j+1] - prefix_sum[i]==k) ct++;
            }
        }
        return ct;
    }
};