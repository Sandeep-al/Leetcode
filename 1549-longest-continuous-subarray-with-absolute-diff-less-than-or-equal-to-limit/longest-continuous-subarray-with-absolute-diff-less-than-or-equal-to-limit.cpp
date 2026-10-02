class Solution {
public:
    multiset<int> st;
    int k;
    int invalid() {

        int mini = *st.begin();
        int maxi = *st.rbegin();

        return !((maxi - mini) <= k);
    }
    int longestSubarray(vector<int>& nums, int limit) {
        k = limit;
        int ans = 0;
        int n = nums.size();
        int l=0;
        for (int r = 0; r < n; r++) {
            st.insert(nums[r]);

            while (invalid()) {
                st.erase(st.find(nums[l]));
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};