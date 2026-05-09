class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        vector<vector<bool>> vis(m , vector<bool>(n,false));
        int x=0,y=0,dir=0;
        int dx[4] = {0 ,1,0 ,-1};
        int dy[4] = {1,0,-1,-0};

        for(int i=0;i<m*n;i++){// a loop over all nos and we will change dirns accordingly
            ans.push_back(matrix[x][y]);
            vis[x][y]= true;

            int nextx= x + dx[dir];
            int nexty = y+ dy[dir];  // like we do in graph but we can fix dirn here so no need for for a for loop over dx and dy;
            if(nextx>=0 && nextx<m && nexty>=0 && nexty<n && !vis[nextx][nexty]){ // isi dirn mein move karenge
                x = nextx;
                y = nexty;
            }
            else{// ya to deadend ya to visited aa gaye - dirn chnage kro right-down-left-up
                dir = (dir+1)%4; //turn 90 deg
                x += dx[dir];
                y += dy[dir];
            }            
        }
        return ans;
    }
};