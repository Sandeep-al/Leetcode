class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {

        int n = nums.size();

        set<int> st;

        int ans = INT_MAX;

        for(int i = x; i < n; i++) {

            st.insert(nums[i - x]);

            auto it = st.lower_bound(nums[i]);

            // >= nums[i]
            if(it != st.end()) {
                ans = min(ans, abs(*it - nums[i]));
            }

            // < nums[i]
            if(it != st.begin()) {
                it--;
                ans = min(ans, abs(*it - nums[i]));
            }
        }

        return ans;
    }
};