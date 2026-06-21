class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // ek soln pq se hai .. nlogk + klogk  mein jayega with sc of O(K);

        // sorted hai toh sare elements ek sath honge with window of k

        int i=0,j=arr.size()-1; 
        // teri wimdow ko shrink kro till it reaches k 

        while(j-i+1>k){
            if(abs(arr[j]-x)>=abs(arr[i]-x)) j--; // agr j wala door hai toh j ko shrink kr;
            else i++;
        }
        // i se j tk ans hai

        return vector<int>(arr.begin()+i , arr.begin()+j+1);

    }
};