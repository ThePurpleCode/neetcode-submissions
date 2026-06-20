class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0); // for 26 uppercase chars;
        int longest =0;
        int i=0,j=0;
        int mxfreq=0;

        while(j<s.size()){
            freq[s[j]-'A']++;

            mxfreq =max(mxfreq ,freq[s[j]-'A']);

            //while loop is shriking wndow
            while((j-i+1)-mxfreq>k){  //  j-i+1 wndo ki len hai toh len-mxfreq k se choti honi tb tk valid hai  while(freq[s[i]-'A']>k) agr ye likha toh bs ek char ki freq k se jyada manege   
                freq[s[i]-'A']--; // agr k se jyada elemnt alag hai toh window size km kr
                i++;

            }
            longest = max(longest,j-i+1);
            j++;
        }
        return longest;
    }
};
