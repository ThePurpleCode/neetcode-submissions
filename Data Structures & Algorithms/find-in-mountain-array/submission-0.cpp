/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // this arr is first inc then dec .. so find peak

        int l=0,r=mountainArr.length()-1;
        int peak =0; // this is idx of peak element

        while(l<r){ // <= nhi hota hai peak ya inflectin points find krne time ... baad mein r =m krna;
            int m = l +(r-l)/2;

            // peak element ka agla chota hona 
            if(mountainArr.get(m)>mountainArr.get(m+1)){ // potential peak hai.. dec slope pe kuch bhi ho sakta aur pahele dhoondh
                r = m; // not r = m-1 coz we could be on potenial peak
            }
            else{ // inc slope pe hai toh age dekh
                l = m+1;
            }
        }
        peak = l;

        // left inc slope

        int l1=0 , r1 = peak;

        while(l1<=r1){
            int m1 = l1 +(r1-l1)/2;

            if(mountainArr.get(m1)==target) return m1;
            else if(mountainArr.get(m1)>target) r1 = m1-1;
            else l1 = m1+1;
        }

        // right dec slope pe dhoondho

        int l2 = peak +1 , r2 =mountainArr.length()-1;

        while(l2<=r2){
            int m2 = l2 +(r2-l2)/2;

            if(mountainArr.get(m2)==target) return m2;
            else if(mountainArr.get(m2)>target) l2 = m2+1; // dec array hai toh ulta logic lagega
            else r2 = m2-1;
        }

        return -1;

    }
};