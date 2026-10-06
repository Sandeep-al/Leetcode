class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        long long count = 0;
        multiset<int> st;
        for (int r = 0; r < n; r++) {
            st.insert(nums[r]);

            while (l <= r && (*st.rbegin() - *st.begin()) > 2) {
                st.erase(st.find(nums[l]));
                l++;
            }

            count += r - l + 1;
        }

        return count;
    }
};