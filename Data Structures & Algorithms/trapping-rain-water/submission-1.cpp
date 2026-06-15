class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1;
        int lmax=0,rmax=0;
        int water =0;

        while(l<=r){
            if(height[l]<height[r]){ // agr left wala chota hai toh limit lmax se set hogi as right side se trap hoga hi water
                if(height[l]>lmax) lmax=height[l]; // agar left ki max km hai toh water trap nhi hoga else hoga
                else water += lmax - height[l];
                l++;
            }
            else{
                if(height[r]>rmax) rmax= height[r]; // same with right side
                else water+= rmax-height[r];
                r--;
            }
        }
        return water;
    }
};