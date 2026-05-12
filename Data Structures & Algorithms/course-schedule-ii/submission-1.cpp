class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);

        for(int i=0;i<n;i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a);
        }
        //indegree for kahns algo
        vector<int> indegree(numCourses,0);
        for(auto x : adj){
            for(auto i :x){
                indegree[i]++;
            }
        }
        queue<int> q; // push all 0 indegrees to queue

        for(int i=0 ; i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> ans; // popped elements of q
        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            ans.push_back(curr);

            // indegree of neigh -1
            for(auto neigh:adj[curr]){
                indegree[neigh]--;
                if(indegree[neigh]==0) q.push(neigh);
            }
        }
        if(ans.size()<numCourses) return {};
        return ans;
    }
};
