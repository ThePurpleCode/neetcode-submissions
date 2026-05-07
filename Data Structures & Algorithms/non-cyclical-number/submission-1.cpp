class Solution {
public:
    int next(int n){
        int tot = 0;
        while(n){
            int dig = n%10;
            tot += dig*dig;
            n /=10;
        }
        return tot;
    }
    bool isHappy(int n) { // 1. happy end with 1 not happy will always end or have 4;
        while(n!=4 && n!=1){
            n = next(n);
        }
        if(n==1) return true;
        else return false;
       
    }
};