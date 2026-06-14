class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j= height.size()-1;
        int area , mxarea=0;
        while(i<j){
            area= (j-i)*(min(height[i],height[j])); // tot area now
            mxarea = max(area,mxarea);
            if(height[i]<height[j]) i++; // agar i ki height choti hai toh i++ dekho warna j--
            else j--;
        }
        return mxarea;
    }
};