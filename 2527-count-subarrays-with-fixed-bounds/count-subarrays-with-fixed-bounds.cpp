class Solution {
public:
    long long solve(vector<int>& nums, int mink, int maxk) {
        int n = nums.size();
        int l = 0;
        long long count = 0;
        multiset<int> st;

        for (int r = 0; r < n; r++) {
            st.insert(nums[r]);

            while (l <= r && (*st.begin() < mink || *st.rbegin() > maxk)) {
                st.erase(st.find(nums[l]));
                l++;
            }

            count += r - l + 1;
        }

        return count;
    }
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        return solve(nums, minK, maxK) - solve(nums, minK + 1, maxK) -
               solve(nums, minK, maxK - 1) + solve(nums, minK + 1, maxK - 1);
    }
};