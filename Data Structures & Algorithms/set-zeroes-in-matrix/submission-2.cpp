class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
// we will use first row and first col as storage as we used 2 vectors for srtrong i and j same here but this storage is in matrix itself
        bool firstrow0 =false , firstcol0 =false; // to check if there are any 0 in first row or col
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                firstcol0 = true;
                break;
            }
        }
        for(int j=0;j<n;j++){
            if(matrix[0][j]==0){
                firstrow0 = true;
                break;
            }
        }

        for(int i=1;i<m;i++){// start with 1 as first row and first col as storage 
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j] =0;
                }
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(firstrow0){
            for(int j=0;j<n;j++) matrix[0][j]=0;
        }
        if(firstcol0){
            for(int i=0;i<m;i++) matrix[i][0]=0;
        }
        return;
        
    }
};