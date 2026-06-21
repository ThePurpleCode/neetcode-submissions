class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int currsum=0;
        int minlen =INT_MAX;

        while(j<nums.size()){
            currsum+= nums[j];
            while(currsum>=target){ // jb tk currsum target se bda hai window valid hai ab i++ krke window shrink krke sabse choti dhoondh
                minlen = min(minlen , j-i+1); // abhi ki min len
                currsum -= nums[i];
                i++;
            }
            j++;
        }
        if(minlen==INT_MAX) return 0;
        return minlen;
        
    }
};