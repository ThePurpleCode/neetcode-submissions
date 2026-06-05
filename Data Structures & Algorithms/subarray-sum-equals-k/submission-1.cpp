class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ct=0;
        int n = nums.size();
        unordered_map<int , int> presum; // freq of sum found till now

        presum[0] =1; // sum till 0 seen once .. before iterating

        int curr_sum=0;
        for(int num:nums){
            curr_sum += num;

            if(presum.find(curr_sum-k) != presum.end()){
                ct += presum[curr_sum-k];
            }
            presum[curr_sum] ++;
        }
        return ct;
        
    }
};