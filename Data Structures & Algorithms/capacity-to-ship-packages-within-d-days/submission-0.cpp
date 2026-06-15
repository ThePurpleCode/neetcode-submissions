class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end()); // low of wt capacity is mx of all elements wrna load hoga hi nhi
        int high=0;
        for(int wt: weights) high += wt; // highest wt capacity is sum of all wts ;

        while(low<=high){
            int mid_cap = low + (high-low)/2;
            int currdays =1;
            int currload=0;

            for(int wt:weights){
                if(currload + wt> mid_cap){ // agr currlaod + w mid_cap yani currnet capacity jispe apn dekh rhe usko exceed kri toh currdays badha 
                    currdays++; 
                    currload = wt; // curr load ko w se start kro
                }
                else{
                    currload+=wt;
                }
            }
            if(currdays<=days) high = mid_cap-1; // agr mid_cap mein horha toh choti wali range mein dekh aur km mil rha kya
            else low = mid_cap+1;
        }
        return low;
    }
};