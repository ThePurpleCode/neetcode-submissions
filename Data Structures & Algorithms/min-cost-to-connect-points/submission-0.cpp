class Solution { // PRIM'S ALGO
public:
    int dist(int x1 , int y1,int x2 , int y2){
        int mandist =abs(x1-x2) + abs(y1-y2);
        return mandist;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // no need to  make adj list as each point is connected to all points so not necessary for this specific ques

        priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>>> keypq; //vector<int> key(n,INT_MAX) iski jagah pq use kr rha ..pair<weight,node>
        vector<bool> mst(n,false);
        vector<int> parent(n,-1); // 3 data struct for prims

        // init
        keypq.push({0,0});
        parent[0] =-1; //already intied

        int ans =0;
        while(!keypq.empty()){
            auto top = keypq.top();
            keypq.pop();

            int wt = top.first;
            int node = top.second;

            if(mst[node]==false){
                mst[node] = true;
                ans += wt;                
            
                for(int v =0;v<n;v++){ // sb pe dekhenge and uske dist pq mein daalnege. min wala uapr aayga and baki vis /mst wale ingnore honge
                    if(!mst[v]){
                        int nextwt = dist(points[v][0],points[v][1],points[node][0],points[node][1]);
                        keypq.push({nextwt,v});
                    }

                }
            }
        }
        return ans;
    }
};