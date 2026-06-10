class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> rightst;
        vector<int> ans;
        for(auto x: asteroids){
            if(x>0){
                rightst.push(x);
            }
            else{
                bool dstroid = false;
                while(!rightst.empty() && rightst.top()<abs(x)){
                    rightst.pop();
                }
                if(!rightst.empty() && rightst.top()== abs(x)){
                    rightst.pop();
                    dstroid = true;
                }
                else if(!rightst.empty() && rightst.top()>abs(x)){
                    dstroid = true;
                }
                if(!dstroid) ans.push_back(x);
            }
        }
        vector<int> remright(rightst.size());
        for(int i=rightst.size()-1;i>=0;i--){
            remright[i] = rightst.top();
            rightst.pop();
        }
        ans.insert(ans.end(),remright.begin(), remright.end());

        return ans;
    }   
};