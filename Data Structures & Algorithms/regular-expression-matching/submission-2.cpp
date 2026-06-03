class Solution {
    public:
        int solve(int i, int j, string& s, string& p ,vector<vector<int>>& dp){
                if(j==p.size()){
                            return i== s.size();
                                    }

                                            if(dp[i][j]!=-1) return dp[i][j];
                                                    bool initial_match = (i<s.size() && (s[i]==p[j] || p[j]=='.'));
                                                            bool ans = false;
                                                                    
                                                                            if(j+1<p.size() && p[j+1]=='*'){
                                                                                        bool skip_this_star = solve(i,j+2,s,p,dp);
                                                                                                    bool take_this_star;// if curr matches use * to match +1 occurrences
                                                                                                                if(initial_match) take_this_star = solve(i+1,j,s,p,dp);

                                                                                                                            ans = (skip_this_star || take_this_star);

                                                                                                                                    }
                                                                                                                                            else{
                                                                                                                                                        ans = initial_match && solve(i+1,j+1,s,p,dp); // intial_match and age bdho 
                                                                                                                                                                }
                                                                                                                                                                        dp[i][j]= ans;
                                                                                                                                                                                return dp[i][j];

                                                                                                                                                                                    }
                                                                                                                                                                                        bool isMatch(string s, string p) {
                                                                                                                                                                                                int n = s.size();
                                                                                                                                                                                                        int m = p.size();

                                                                                                                                                                                                                vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

                                                                                                                                                                                                                        return solve(0,0,s,p,dp);
                                                                                                                                                                                                                            }
                                                                                                                                                                                                                            };

