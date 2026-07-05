class Solution { // n+1 tk hi nos hone and 1 hi repeat hona
public: // ll se like cycle in ll se solve kro
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        while(true){
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(slow == fast ) break;  // cyccle exist krti hai
        }
        slow = nums[0];
        while(slow != fast){ // ye kaise hota mereko nhi malum pr hota hai
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};