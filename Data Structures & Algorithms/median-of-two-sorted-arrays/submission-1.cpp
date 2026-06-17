class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size() , n = nums2.size(); // assuming m <=n .. coz we are searching in smaller array

        if(m>n) return findMedianSortedArrays(nums2 , nums1); // agr m bda toh reverse krna

        // apne ko dono array ke left mein konse element rahenge ye dekhna median se .. as median ki pos fix hai
        int halflen = (m+n+1)/2;
        int low =0, high = m; // 1st arrat ke kitne elements median ke left mein rahenege uske upar binary search laga .. high is m as sare bhi reh sakte

        while(low<=high){
            int i = low + (high-low)/2; // ye nums 1 ka pointer hai .. i elements to left of median
            int j = halflen -i; // j elements of nums2 before median
            int l1 ,l2,r1,r2; // ye 4 cuts/pointers hai 
            // final array ka left part {......l1......l2} , right part {r1.......r2......};

            // nums1 mein jo left elements ka mx hai wo l1 and right elements ka min is r1

            if(i==0){// nums1 ke 0 elements hai median ke left mein toh l1 ko INT_MIN maan ekdum chota
                l1=INT_MIN; 
            }
            else{
                l1 = nums1[i-1]; // else normal sa i elements to l1 is nums[i-1];
            }

            if(i==m){ // agr nums1 ke sare eleemnts hai left mein toh r1 kuch nhi hoga toh ekdum max kuch maan liya
                r1 = INT_MAX;
            }
            else{
                r1 = nums1[i];
            }

            // same with nums2 & j
            if(j==0){
                l2= INT_MIN; 
            }
            else{
                l2 = nums2[j-1]; 
            }

            if(j==n){
                r2 = INT_MAX;
            }
            else{
                r2 = nums2[j];
            }


            // core logic .. ab throughout process l1<=r1 and l2<=r2

            if(l1<=r2 && l2<=r1){ // we found partitaion .""CROSSOVER IS IMP""
                if((m+n)%2==1){//agr odd elements toh mx of l1 ,l2
                    return (double)max(l1,l2);
                }
                else{ //eve elements toh avg of lmx and rmin
                    return (double)(max(l1,l2) + min(r1,r2))/2;
                }
            }
            else if(l1>r2){
                high = i-1; // nums1 ke jyada elements aye toh km kro
            }
            else if(l2>r1){
                low = i+1; // nums1 ke km elements aye toh badhao ... as i is no elements of nums1 to left of median
            }
        }
        return 0.0;

    }
};