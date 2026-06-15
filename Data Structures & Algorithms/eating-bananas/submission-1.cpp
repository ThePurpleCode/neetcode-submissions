class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l =1;
        int high = *max_element(piles.begin(),piles.end()); // low and high of bananas/hr low_k , high_k
        int time =0;

        while(l<=high){
            int mid_k = l +(high-l)/2;

            for(int i=0;i<piles.size();i++){
                time = time + (piles[i] +mid_k -1)/mid_k; // agar wo mid_k ke speed se kha rha toh kitna time lagega .. cellling div of piles[i]/speed(mid_k)... celling[y/x] = y+x-1/x
            }
            if(time<=h) high=mid_k-1; // agar chota hai toh ye potential ans ho sakta hai .. aur choti range mein dekh
            else l = mid_k+1; // agar nhi toh badi range mein dekh;
            time=0; // wapas naye ke liye time 0 pe init kr de;
        }
        return l; // lowest ans return karna hai;
    }
};