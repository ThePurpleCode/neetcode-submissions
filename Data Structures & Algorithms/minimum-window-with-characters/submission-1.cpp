class Solution {
public:
    bool isvalidwndo(unordered_map<char ,int>& freqt ,unordered_map<char , int>& freqs){
        for(auto x:freqt){
            if(freqs[x.first]<x.second) return false; 
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char ,int> freqt;
        unordered_map<char , int> freqs;
        int minlen =INT_MAX;
        int stidx=-1;

        for(char c:t){
            freqt[c]++;
        }
        int i=0,j=0;
        while(j<s.size()){
            freqs[s[j]]++;

            while(isvalidwndo(freqt , freqs)){
                if(j-i+1 < minlen){
                    minlen = j-i+1;
                    stidx =i;
                }
                freqs[s[i]]--;
                i++;
            }
            j++;
        }
        if(stidx==-1) return "";
        return s.substr(stidx,minlen);
    }
};