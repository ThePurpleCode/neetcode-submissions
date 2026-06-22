class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // jo curr window ke elements ko set mein daal taki max set.rbegin() se acces kr paye

        multiset<int> st;
        vector<int> ans;

        int i=0,j=0;
        while(j<nums.size()){
            st.insert(nums[j]);
            if(j-i+1<k) j++; // wndo size k pe leke aa
            else if(j-i+1==k){
                ans.push_back(*st.rbegin());
                auto it = st.find(nums[i]); // ith element ko dhoondh ke set se nikal
                st.erase(it);
                i++;
                j++;
            }

        }
        return ans;
    }
};