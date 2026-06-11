class Solution {
public:
    string decodeString(string s) {
        stack<int> numst;
        stack<string> strst;
        int num=0;
        string currstr ="";

        for(char c:s){
            if(isdigit(c)){
                num = num*10 + (c-'0');
            }
            else if(c=='['){
                numst.push(num);
                num =0;
                strst.push(currstr);
                currstr = "";
            }
            else if(c==']'){
                string temp = currstr;
                currstr = strst.top();
                strst.pop();
                int repeat = numst.top();
                numst.pop();

                while(repeat--){
                    currstr += temp;
                }

            }
            else{
                currstr += c;
            }
        }
        return currstr;
    }
};