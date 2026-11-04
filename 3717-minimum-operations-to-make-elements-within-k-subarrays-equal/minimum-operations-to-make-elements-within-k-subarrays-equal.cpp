class Solution {
public:
    vector<vector<long long>> dp;

    void balance(multiset<int>& left, multiset<int>& right, long long& left_sum,
                 long long& right_sum) {

        int left_size = left.size();
        int right_size = right.size();

        if (right_size - left_size == 2) {
            int first_element = *right.begin();
            right_sum -= first_element;
            right.erase(right.begin());

            left.insert(first_element);
            left_sum += first_element;
        }

        if (left_size == right_size + 1) {
            int last_element = *prev(left.end());
            left_sum -= last_element;
            left.erase(prev(left.end()));

            right.insert(last_element);
            right_sum += last_element;
        }
    }

    long long solve(int idx, vector<long long>& cost, int count, int x, int k,
                    int n) {

        if (count == 0)
            return 0;

        if (idx >= n)
            return 1e18;

        if (n - idx < count)
            return 1e18;

        if (dp[idx][count] != -1)
            return dp[idx][count];

        // Skip current window
        long long cost1 = solve(idx + 1, cost, count, x, k, n);

        // Take current window
        long long cost2 = cost[idx] + solve(idx + x, cost, count - 1, x, k, n);

        return dp[idx][count] = min(cost1, cost2);
    }

    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();
        multiset<int> left;
        multiset<int> right;
        long long left_sum = 0;
        long long right_sum = 0;
        vector<long long> cost;

        for (int i = 0; i < n; i++) {

            if (right.empty() || nums[i] >= *right.begin()) {
                right.insert(nums[i]);
                right_sum += nums[i];
            } else {
                left.insert(nums[i]);
                left_sum += nums[i];
            }

            balance(left, right, left_sum, right_sum);

            if (i >= x) {
                int to_remove = nums[i - x];

                if (left.find(to_remove) != left.end()) {
                    left.erase(left.find(to_remove));
                    left_sum -= to_remove;
                } else {
                    right.erase(right.find(to_remove));
                    right_sum -= to_remove;
                }

                balance(left, right, left_sum, right_sum);
            }

            if (i >= x - 1) {
                long long curr_median = *right.begin();

                long long cost1 =
                    llabs(left_sum - (1LL * left.size() * curr_median));

                long long cost2 =
                    llabs(right_sum - (1LL * right.size() * curr_median));

                cost.push_back(cost1 + cost2);
            }
        }

        int m = cost.size();

        dp.assign(m + 1, vector<long long>(k + 1, -1));

        return solve(0, cost, k, x, k, m);
    }
};