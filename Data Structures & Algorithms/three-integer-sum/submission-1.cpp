class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;

        for(int k=0;k<nums.size()-2;k++){
            if(k>0 && nums[k]==nums[k-1]) continue; // agar dono same hai toh age badhao
            int i = k+1; // k ke age dekh lo sb
            int j = nums.size()-1;

            while(i<j){
                if(nums[i]+nums[j]> -nums[k]){ // -nums[k] is like target in two sum
                    j--;
                }
                else if(nums[i]+nums[j]< -nums[k]){
                    i++;
                }
                else if(nums[i]+nums[j]== -nums[k]){
                    ans.push_back({nums[i],nums[j],nums[k]}); // agar mil gaya toh i++ j-- tb tk jb tk elements same ho
                    while(i<j && nums[i]==nums[i+1]) i++;
                    while(i<j && nums[j]==nums[j-1]) j--; 
                    i++ , j--;
                }
            }
        }
        return ans;
    }
};