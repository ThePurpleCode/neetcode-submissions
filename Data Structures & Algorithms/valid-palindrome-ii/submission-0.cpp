class Solution {
public:
    bool palin(string s , int st , int end){
        while(st<=end){
            if(s[st]!=s[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;

        while(i<=j){
            if(s[i] != s[j]){
                bool r = palin(s,i+1,j);
                bool l = palin(s,i,j-1);

                return r||l;
            }
            i++;
            j--;
        }
        return true;
    }
};