class Solution {
public:
    int dist(int x1 , int y1 , int x2 , int y2){
        return abs(x1-x2) + abs(y1-y2);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        // no need for adj list as all points may get connected 
        int n = points.size();

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> keypq; //pair<wt,node> vector<int> key(n,INT_MAX) ki jagah pq us ekr rhe taki min dhoondhna asan ho
        vector<bool> vis(n,false);
        vector<int> par(n,-1);

        //init
        keypq.push({0,0});
        par[0] =-1;

        int cost =0; 
        while(!keypq.empty()){
            auto top = keypq.top();
            keypq.pop();

            int wt = top.first;
            int node = top.second;

            if(vis[node]==false){//agr ye node vis nhi hai toh hi dekhna wrna bhul jaa
                vis[node] = true;
                cost += wt;

                for(int neigh =0;neigh<n;neigh++){ // iske neigh dekh le (ab yaha adj list nhi hai toh sare nodes/points pe dekhte hai)
                    int nxtwt = dist(points[node][0],points[node][1],points[neigh][0],points[neigh][1]); //is neigh and node ke beech ka dist push kr de pq mein agar min hai and unvisted hai toh aayega warna peace maar
                    keypq.push({nxtwt,neigh});           
                }
            }
        }
        return cost;
    }
};
