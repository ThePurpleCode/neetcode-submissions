class Solution {
public:
    int calPoints(vector<string>& operations) {
        int totscore=0;
        stack<string> st;

        for(auto op:operations){
            if(!st.empty()  && op=="D"){
                int top = stoi(st.top());
                totscore += 2*top;
                st.push(to_string(2*top));
            }
            else if(!st.empty() && op=="C"){
                totscore -= stoi(st.top());
                st.pop();
            }
            else if(!st.empty() && op=="+"){
                int first = stoi(st.top());
                st.pop();
                int second = stoi(st.top());
                totscore += (first + second);

                st.push(to_string(first));
                st.push(to_string(first+second));
            }
            else{
                totscore += stoi(op);
                st.push(op);
            }
        }
        return totscore;
    }
};