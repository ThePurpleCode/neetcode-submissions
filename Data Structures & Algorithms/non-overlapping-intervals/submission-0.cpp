class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        multimap<int,int> mp; // end , start ... end se sort karna hai yaha

        for(auto x:intervals){
            mp.insert({x[1],x[0]});
        }
        int del =0;
        auto it=mp.begin();
        while(it!=mp.end()){
            auto nxt = next(it);
            if(nxt==mp.end()) break;

            int curr_end = it->first;
            int nxt_st = nxt->second;

            if(nxt_st<curr_end){
                del++;
                mp.erase(nxt);
            }
            else it++;
        }
        return del;
    }
};
