class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // sort(nums.begin(),nums.end());
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;

    }
};