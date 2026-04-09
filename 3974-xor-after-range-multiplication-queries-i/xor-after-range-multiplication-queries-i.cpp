class Solution {
public:
    int l;
    int r;
    int k;
    int v;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (auto& it : queries) {

            l = it[0];
            r = it[1];
            k = it[2];
            v = it[3];

            while (l <= r) {
                nums[l] = ((long long)nums[l] * (long long)v) % (1000000007);
                l += k;
            }
        }

        int ans = 0;
        for (auto& jt : nums) {
            ans = ans ^ jt;
        }

        return ans;
    }
};