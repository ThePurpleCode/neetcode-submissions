class Solution {
public: // NEW DATA STRUCT "stringstream"
    string simplifyPath(string path) {
        vector<string> simple;

        stringstream ss(path); // creates a stringstream like it makes a large string (path) into short strings like cin or cout
        string segment;
        while(getline(ss,segment,'/')){// getline(input,string,delimeter) .. ss (input) se utha ke string mein dal and '/' aya toh string lena band kr 
            if(segment=="" || segment =="."){
                continue; //agar empty string (//) ya . hai same directory toh cont
            }
            else if(simple.size()!=0 && segment ==".."){
                simple.pop_back();
            }
            else if(segment=="..") continue;
            else{
                simple.push_back(segment);
            }

        }
        string ans ="";       
        for(auto str :simple){
            ans += "/" + str;
        }
        if(simple.size()==0) ans = "/";
        return ans;
    }
};