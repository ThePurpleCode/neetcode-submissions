/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        multimap<int , int> mp; // start,end; multimap as it will handle duplicates keys

        for(auto x:intervals){
            int st = x.start;
            int end = x.end;

            mp.insert({st,end});
        }
        bool conflit =false;
        for(auto it=mp.begin();it!=mp.end();it++){
            auto nxt = next(it);

            if(nxt== mp.end()) break;

            if(nxt->first < it->second){
                conflit = true;
                break;
            }
        }
        return !conflit;
    }
};
