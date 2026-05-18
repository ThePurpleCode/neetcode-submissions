class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxele(n , vector<int>(n,INT_MAX)); // this stores max elevation till this point .. dijkstra mein dist array hota hai toh apn min dist store karte hai idhar max elevation till that point store karna hai and isi ka min ans hai
        maxele[0][0] = grid[0][0];

        priority_queue<pair<int , pair<int,int>> , vector<pair<int , pair<int,int>>> , greater<pair<int , pair<int,int>>>> pq; // pair<mxelevation , pair<x,y>>
        pq.push({maxele[0][0],{0,0}});

        int dirx[4]  = {1,-1,0,0};
        int diry[4]  = {0,0,1,-1};
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int currmx = top.first;
            int x = top.second.first;
            int y = top.second.second;

            // as this is grid we will traverse like we did in rotten oranges ques ...4 dir 

            for(int k=0;k<4;k++){
                int nx = x + dirx[k];
                int ny = y + diry[k];

                if(nx>=0 && nx<n && ny>=0 && ny<n){
                    int newmx = max(currmx , grid[nx][ny]);

                    if(newmx<maxele[nx][ny]){
                        maxele[nx][ny] = newmx;
                        pq.push({maxele[nx][ny] , {nx,ny}});
                    }
                }
            }
            
        }
        return maxele[n-1][n-1];
    }
};
