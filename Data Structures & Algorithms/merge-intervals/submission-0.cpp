class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            vector<int>& prev = ans.back(); // checking with last interval pushed in ans -- & as it will update insiude ans as we passed it by refernce
            vector<int> curr = intervals[i];

            if(curr[0]<=prev[1]){// overlap - update end of last interval
                prev[1] = max(prev[1],curr[1]);
            } 
            else{ // no overlap push curr as new interval
                ans.push_back(curr);
            }
        }
        return ans;
    }
};
