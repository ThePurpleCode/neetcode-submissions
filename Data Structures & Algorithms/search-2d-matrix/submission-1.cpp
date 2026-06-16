class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int top = 0, bottom = rows-1;
        int target_row=-1;

        while(top<=bottom){
            int row_mid = top + (bottom-top)/2;

            if(matrix[row_mid][0]==target) return true;

            else if(matrix[row_mid][0]<=target && matrix[row_mid][cols-1]>=target){
                target_row = row_mid;
                break;
            }
            else if(matrix[row_mid][0]>target){
                bottom = row_mid-1;
            }
            else{
                top = row_mid+1;
            }
        }

        if(target_row==-1) return false; // agr target row nhi mili toh element hai hi nahi

        int l = 0, r=cols-1; // search in target row now;
        while(l<=r){
            int m = l+(r-l)/2;

            if(matrix[target_row][m]==target) return true;
            else if(matrix[target_row][m]>target){
                r = m-1;
            }
            else l = m+1;
        }
        return false;
    }
};