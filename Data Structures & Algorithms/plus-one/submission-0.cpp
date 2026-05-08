class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        bool carry = true;
        for(int i = n-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]++;
                carry = false;
                break;
            }
            else digits[i]=0;
        }
        if(carry) digits.insert(digits.begin(),1);
        return digits;

    }
};