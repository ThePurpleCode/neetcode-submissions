class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(auto num:nums) ans.push_back(num);
        for(auto num:nums) ans.push_back(num);
        return ans;
    }
};