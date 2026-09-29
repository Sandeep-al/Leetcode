class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        set<pair<int, int>> st;
        int n=nums.size();
        for (int i = 0; i < k; i++) {
            st.insert({nums[i], i});
        }

        vector<int> ans;
        ans.push_back((*st.rbegin()).first);

        for (int i = k; i < n; i++) {
            st.insert({nums[i], i});
            st.erase({nums[i - k], i - k});
            ans.push_back((*st.rbegin()).first);
        }

        return ans;
    }
};