class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; // st mein index daleneg
        heights.push_back(0); // end mein 0 push kro taki sare elements pop ho sake
        int n = heights.size(); // n updated array ki size hai
        // logic is - for every element we calculate its prev smaller and next smaller so that we can get maxarea at this point
        int mxarea =0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]< heights[st.top()]){ // curr height choti hai st ke top se toh curr next smaller hai and st.top() ke neeche ka prev smaller hai
                int h = heights[st.top()];
                st.pop();

                int w;
                // agar st empty hua matlab ye shortest hai as st mein iske neeche wala prev shorter hai toh w = 0-i
                if(st.empty()) w = i;
                else w = i-st.top()-1; // apn ith index ka max area dekh rhe

                mxarea = max(mxarea , h*w);

            }
            st.push(i);
        }
        return mxarea;
    }
};
