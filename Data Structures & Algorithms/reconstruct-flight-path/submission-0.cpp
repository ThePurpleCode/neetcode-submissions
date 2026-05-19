class Solution { //" Hierholzer’s Algorithm" for euclidean dist where we can visit node(airport) more that once but not edge(ticket);
public:
    unordered_map<string , priority_queue<string , vector<string> , greater<string>>> adj;
    vector<string> ans;
    void dfs(string curr){
        while(!adj[curr].empty()){
            //while avalable tickets from this airport
            string nxt_dst = adj[curr].top();
            adj[curr].pop();

            dfs(nxt_dst);
        }
        ans.push_back(curr);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        

        for(int i=0;i<tickets.size();i++){
            string frm = tickets[i][0];
            string to = tickets[i][1];

            adj[frm].push(to);
        }
        dfs("JFK");// src airport (starting airport)

        reverse(ans.begin(),ans.end());
        return ans;
        


    }
};
