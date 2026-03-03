class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int current_max = INT_MIN;

        for (int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            current_max = max(current_max, nums[i][0]);
        }

        vector<int> range = {INT_MIN, INT_MAX};

        while (true) {
            auto curr = pq.top();
            pq.pop();

            int min_value = curr[0];
            int list_idx = curr[1];
            int elem_idx = curr[2];

            if ((long long)current_max - min_value < (long long)range[1] - range[0]) {
                range = {min_value, current_max};
            }

            if (elem_idx + 1 < (int)nums[list_idx].size()) {
                int next_val = nums[list_idx][elem_idx + 1];
                pq.push({next_val, list_idx, elem_idx + 1});
                current_max = max(current_max, next_val);
            } else {
                break;
            }
        }

        return range;
    }

    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0, count2 = 0;

        vector<vector<int>> solve1, solve2;

        // Pass 1: index 0 = even, index 1 = odd, ...
        for (int i = 0; i < n; i++) {
            int expected = i % 2; // 0=even, 1=odd
            if (abs(nums[i]) % 2 != expected) {
                count1++;
                solve1.push_back({nums[i] - 1, nums[i] + 1});
            } else {
                solve1.push_back({nums[i]});
            }
        }

        // Pass 2: index 0 = odd, index 1 = even, ...
        for (int i = 0; i < n; i++) {
            int expected = 1 - (i % 2); // 1=odd, 0=even
            if (abs(nums[i]) % 2 != expected) {
                count2++;
                solve2.push_back({nums[i] - 1, nums[i] + 1});
            } else {
                solve2.push_back({nums[i]});
            }
        }

        // Early exit: already alternating
        // spread = max - min of original array
        if (count1 == 0) {
            int mn = *min_element(nums.begin(), nums.end());
            int mx = *max_element(nums.begin(), nums.end());
            return {0, mx - mn};
        }
        if (count2 == 0) {
            int mn = *min_element(nums.begin(), nums.end());
            int mx = *max_element(nums.begin(), nums.end());
            return {0, mx - mn};
        }

        if (count1 < count2) {
            auto it = smallestRange(solve1);
            return {count1, it[1] - it[0]};
        } else if (count2 < count1) {
            auto it = smallestRange(solve2);
            return {count2, it[1] - it[0]};
        } else {
            // count1 == count2
            auto it = smallestRange(solve1);
            auto jt = smallestRange(solve2);
            return {count1, min(it[1] - it[0], jt[1] - jt[0])};
        }
    }
};