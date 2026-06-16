class Solution {
public:
    int search(vector<int>& nums, int target) {
        // first find index of min to get by how much array is rotated

        int l =0, h = nums.size()-1;

        while(l<h){
            int m = l +(h-l)/2;

            if(nums[m]>nums[h]) l = m+1;
            else h=m;
        }
        // now at lth index there is smallest ele .. array is rortated by l

        if(l==0){ // agr array rotate hi hua toh normal binary search
            int l1 =0,h1 =nums.size()-1;

            while(l1<=h1){
                int m1 = l1 +(h1-l1)/2;

                if(nums[m1]==target) return m1;
                else if(nums[m1]>target) h1 = m1-1;
                else l1 = m1+1;
            }
        }

        else if(nums[0]<=target && nums[l-1]>=target){ // roateded mein first sorted half
            int l1 =0,h1 =l-1;

            while(l1<=h1){
                int m1 = l1 +(h1-l1)/2;

                if(nums[m1]==target) return m1;
                else if(nums[m1]>target) h1 = m1-1;
                else l1 = m1+1;
            }
        }
        else{ // rotated mein second half
            int l2 =l,h2 =nums.size()-1;

            while(l2<=h2){
                int m2 = l2 +(h2-l2)/2;

                if(nums[m2]==target) return m2;
                else if(nums[m2]>target) h2 = m2-1;
                else l2 = m2+1;
            }
        }
        return -1;
    }
};