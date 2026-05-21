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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()){
            return 0;
        }
        sort(intervals.begin(), intervals.end(),[](const Interval& a , const Interval& b){
            return a.start < b.start;
        });

        priority_queue<int , vector<int> , greater<int>> pq; // this stores end time .. size of this is ans 

        pq.push(intervals[0].end); // end time of first interval(sorted);

        for(int i=1;i<intervals.size();i++){
            int curr_st = intervals[i].start;
            int curr_end = intervals[i].end;

            if(curr_st>=pq.top()){// agar curr st sabse jaldi khatam hone wali meet se bada hai toh room nhi lagegi-pq ki size nhi badhegi
                pq.pop(); // free this room(as sabse jaldi wali meet khatam ho chuki hai)
            }
            pq.push(curr_end);
        }
        return pq.size();
    }
};
