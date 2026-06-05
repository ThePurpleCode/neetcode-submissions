class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sm = 1;
        unordered_map<int,int> freq;
        for(int num :nums){
            if(num>0) freq[num]++;
        }
        while(true){
            if(freq.find(sm) != freq.end()){
                sm++;
            }
            else return sm;
        }
    }
};