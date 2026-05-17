class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<flights.size();i++){
            int frm = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];

            adj[frm].push_back({to,price});
        }

        vector<int> mincst(n,INT_MAX); // dist array in dijkstra -> min cst from src
        mincst[src] =0;

        queue<pair<int,int>> q; //pair<mincst from src , node>.. queue here as we dont need to have min dist like in standerd dijkstra
        q.push({0,src});

        int stops=0;

        while(!q.empty() && stops<=k){
            int sz = q.size();

            while(sz--){
                auto curr = q.front();
                q.pop();

                int currcost = curr.first;
                int node = curr.second;

                for(auto& neigh:adj[node]){
                    int price = neigh.second;
                    int neighnode = neigh.first;

                    if(currcost + price <mincst[neighnode]){
                        mincst[neighnode] = currcost + price;
                        q.push({mincst[neighnode],neighnode});
                    }
                }
            }
            stops++;
        }
        if(mincst[dst]==INT_MAX) return -1;
        return mincst[dst];

    }
};
