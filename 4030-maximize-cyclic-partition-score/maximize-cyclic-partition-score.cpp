class Solution {
public:
    long long maximumScore(vector<int>& nums, int k) {
        int n = (int)nums.size();

        auto solve = [&](int base) -> long long {
            base %= n;

            const long long NEG_INF = -(1LL << 60);
            vector<long long> dp(n + 1, 0);
            long long result = 0;

            for (int used = 0; used < k; ++used) {
                vector<long long> ndp(n + 1, NEG_INF);
                long long x = NEG_INF, y = NEG_INF;

                for (int j = used; j < n; ++j) {
                    long long val = nums[(base + j) % n];

                    x = max(x, dp[j] - val);
                    y = max(y, dp[j] + val);

                    ndp[j + 1] = max({ndp[j], x + val, y - val});
                }

                dp = move(ndp);
                result = max(result, dp.back());
            }

            return result;
        };

        int mnIdx =
            min_element(nums.begin(), nums.end()) - nums.begin();

        return max(solve(mnIdx), solve(mnIdx + 1));
    }
};