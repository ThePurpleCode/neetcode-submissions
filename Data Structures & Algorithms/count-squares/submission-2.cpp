class CountSquares {
public:
    map<pair<int,int>,int> freq;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x= point[0];
        int y = point[1];

        freq[{x,y}]++;

        return;
    }
    
    int count(vector<int> point) {
        int x =point[0];
        int y = point[1];
        int ans =0;

        for(auto& p:freq){
            int x1 = p.first.first;
            int y1 = p.first.second;
            int duplis = p.second;

            if(x1==x || y==y1) continue;
            if(abs(x1-x) != abs(y1-y)) continue;

            ans += duplis*freq[{x1,y}]*freq[{x,y1}];
        }
        return ans;
    }
};

