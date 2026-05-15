class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //dijkstra algo

        vector<vector<pair<int,int>>> adj(n+1);

        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v,w}); // adj list (directed)
        }

        vector<int> dist(n+1,INT_MAX); // min dist of node from src node

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq; // pair<dist from src , node>

        //initialise src node
        dist[k] = 0;
        pq.push({0,k}); // k is src node

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            int srcdist = top.first;
            int topnode = top.second;

            for(auto& neigh:adj[topnode]){
                if(srcdist +neigh.second< dist[neigh.first]){
                    dist[neigh.first] = srcdist + neigh.second; // core dijkstra loop
                    pq.push({dist[neigh.first],neigh.first});
                }
            }
        }
        int ans =0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            ans = max(ans,dist[i]); // min time is min time for farthest one;
        }
        return ans;
    }
};
