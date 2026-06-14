class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int boats=0;

        int i=0,j=people.size()-1;
        while(i<=j){
            // if(people[j]>=limit){
            //     boats++;
            //     j--;
            // }
            if(people[j]+people[i]>limit){
                boats++;
                j--;
            }
            else if(people[j]+people[i]<=limit){
                boats++;
                i++;
                j--;
            }
        }
        return boats;
    }
};