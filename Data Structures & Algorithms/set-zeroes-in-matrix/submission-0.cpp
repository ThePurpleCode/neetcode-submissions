class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); 
        int n = matrix[0].size();
        vector<int> row;
        vector<int> col;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for(int k=0 ;k<row.size();k++){// r.size() = c.size();
            int r = row[k];
            int c = col[k];

            for(int i=0;i<m;i++){
                matrix[i][c] =0;
            }
            for(int j=0;j<n;j++){
                matrix[r][j] =0;
            }
            
        }
        return;
    }
};