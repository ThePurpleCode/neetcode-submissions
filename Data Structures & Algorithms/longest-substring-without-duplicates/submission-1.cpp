class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256,0);
        int longest =0;
        int i=0,j=0;
        while(j<s.size()){
            freq[(unsigned char)s[j]]++; // j ko iterate kro .. pehele jth char ki freq badha

            // ab agr repeat hua toh kisi ki toh freq 1 se jyda hogi usko km kr
            // tb tk i pointer ko age bdha jb tk s[j] ka count jo abhi abhi 1 se jyada hua wo 1 tk aa jaye

            while(freq[(unsigned char)s[j]]>1){
                freq[(unsigned char)s[i]]--;
                i++;
            }
            longest = max(longest,j-i+1);
            j++;
        }
        return longest;
    }
};