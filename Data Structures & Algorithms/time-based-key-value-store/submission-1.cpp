class TimeMap {
public:
    unordered_map<string, vector<pair<int , string>>> mp; // key , vector<time , value>
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
        return;
    }
    
    string get(string key, int timestamp) { // to this get func we will apply binary search
        auto &vec= mp[key]; // &vec due to if we did auto vec = mp[key] .. it will create a copy of map so it will create n copies so our code will have tc of O(N) thats why we passed it as refrence
        int l =0,r = vec.size()-1;

        string ans ="";

        while(l<=r){
            int m = l +(r-l)/2;
            if(vec[m].first <=timestamp){
                ans = vec[m].second; // potential ans 
                l = m+1; // as we want max so agr ans mila toh abdi range mein dhoondh
            } 
            else{
                r = m-1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
 