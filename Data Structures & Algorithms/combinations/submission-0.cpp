class Solution {
public:
    void solve(int i,int n, int k,vector<int>& set,vector<vector<int>>& ans){
        if(set.size()==k){
            ans.push_back(set);
            return;
        } 

        int need = k-set.size(); // this is no of more elements needed

        for(int j = i; j<=n-need+1;j++){
            set.push_back(j);// ya toh element lo backtrack krke age bdho
            solve(j+1,n,k,set,ans);
            set.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> set;
        vector<vector<int>> ans;
        solve(1,n,k,set,ans);
        return ans;

    }
};