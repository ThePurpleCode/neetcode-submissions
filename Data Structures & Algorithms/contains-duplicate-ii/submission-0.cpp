class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //hash map with last seen idx;
        unordered_map<int , int> mp; //elemwnt , idx>
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                if(i-mp[nums[i]]<=k) return true;
            }
            
            mp[nums[i]]=i;
            
        }
        return false;
    }
};