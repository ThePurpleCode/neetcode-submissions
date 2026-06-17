class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // apn dekhenge ki can i split this array in k parts with sum s . and we will look for min s via binary search

        int l = *max_element(nums.begin(),nums.end());
        int h=0;
        for(int i=0;i<nums.size();i++) h+=  nums[i];

        int ans = h; // ans ko minimize krna hai to mx pe init kr diya

        while(l<=h){
            int m = l +(h-l)/2; // ab m is my target of largest sum of subarray

            int currk =1;
            int currsum=0;
            bool poss = true; // bool of kya ye sum pe k splits possible hai 

            for(int num:nums){
                if(currsum + num>m){ // split mil gaya
                    currsum = num; // currsum num pe init ho gayi as apn split kia;
                    currk++;

                    if(currk>k){
                        poss = false;
                        break;
                    }
                }
                else {
                    currsum += num;
                }
               
            }

            if(poss){ // agr possible hai toh m probable ans hai .... aur chota dhoondo
                ans =m;
                h = m-1;
            }
            else{ // m bahot chota ho gaya poss nhi hai toh bada dhoondho
                l = m+1;
            }
        }
        return ans;

    }
};