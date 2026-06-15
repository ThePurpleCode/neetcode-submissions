class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int l =0;
        int h = x;
        int ans=0;

        while(l<=h){
           long long int m = l + (h-l)/2;
            if(m*m<=x){ // agr m^2 x se chota hai toh m potential candi hai
                ans =m;
                l = m+1; // aur bada candi dhoondh
            }
            else h = m-1;
        }
        return ans;
    }
};