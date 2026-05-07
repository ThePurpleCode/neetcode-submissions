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
    bool isHappy(int n) { // cycle detection floyd algo linked list hare and tortoise 
        int slow =n;
        int fast = next(n);
        while(fast!=1 && slow!=fast){
            slow = next(slow);
            fast = next(next(fast));
        }

        if(fast==1) return true;
        return false;

    }
};