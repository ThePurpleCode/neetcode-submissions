class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n;i++){ 
            while(nums[i]>0 && nums[i]<=n &&nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);    // agr positive hai toh us no ko uske index pe dal like 2 goes to 2nd place i.e index 1
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};

// tc O(n) hai kyoki total swaps at max n is ho sakte hai