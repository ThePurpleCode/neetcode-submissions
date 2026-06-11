class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; // st mein indices store karenge
        heights.push_back(0); // end mein 0 push karo taaki saare remaining elements pop ho jayein
        int n = heights.size(); 
        // Logic: har bar ke liye 'prev smaller' aur 'next smaller' boundary dhund rahe taaki max area mile
        int mxarea = 0;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[i] < heights[st.top()]) { 
                // heights[i] chota hai, matlab 'i' next smaller hai aur stack ka naya top 'prev smaller' hoga
                int h = heights[st.top()];
                st.pop();

                int w;
                // Agar stack empty hai, matlab popped element ab tak ka sabse chota tha, toh width 'i' hogi
                if(st.empty()) w = i;
                // Warna 'i' right boundary hai aur 'st.top()' left boundary, width = i - st.top() - 1
                else w = i - st.top() - 1; 

                // Yahan hum popped height 'h' ke liye max area calculate kar rahe
                mxarea = max(mxarea, h * w);
            }
            st.push(i);
        }
        return mxarea;
    }
};