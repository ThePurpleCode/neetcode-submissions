class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        int n = intervals.size();
        int q = queries.size();

        sort(intervals.begin(),intervals.end());
        vector<pair<int , int>> sorted_queries;
        for(int i=0;i<q;i++){
            sorted_queries.push_back({queries[i],i}); // queries ko sort kara . index ka track rakhna hai
        }
        sort(sorted_queries.begin(), sorted_queries.end());
     
        priority_queue<pair<int ,int> , vector<pair<int ,int>> , greater<pair<int ,int>>> pq;// <size of inteerval, endtime>

        vector<int> ans(q);
        int i=0; // i intervals mein tracverse hoga
        for(int j=0;j<q;j++){
            int query_val = sorted_queries[j].first;
            int query_idx = sorted_queries[j].second;

            while(i<n && intervals[i][0]<=query_val){ // interval ka start time query val se pahele start ho rhe
                int interval_size = intervals[i][1] - intervals[i][0] +1;
                pq.push({interval_size, intervals[i][1]}); // pq mein size and end time dalo pq ka
                i++; 

            }
            while(!pq.empty() && pq.top().second<query_val){
                pq.pop(); // interval ki sabse choti size check kri agar query_val is interval ke end se badi hai toh wo interval mein nhi hai toh pop it out
            }
            // sabse choti interval jismein query val hai wo pq.top pe hogi

            if(!pq.empty()) ans[query_idx] = pq.top().first;
            else ans[query_idx] = -1;
        }
        return ans;
        

    }
};
