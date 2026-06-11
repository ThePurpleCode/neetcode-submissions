class FreqStack {
public:
    unordered_map<int ,int> freq; // freq of each val
    unordered_map<int , stack<int>> grp; // grp of elemetns having same freq;
    int mxfreq;
    FreqStack() {
        mxfreq=0;
    }
    
    void push(int val) {
        int f = freq[val]++;
        grp[f].push(val);

        if(f>mxfreq) mxfreq=f;
    }
    
    int pop() {
        int val = grp[mxfreq].top();
        grp[mxfreq].pop();

        freq[val]--;
        if(grp[mxfreq].empty()) mxfreq--;

        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */