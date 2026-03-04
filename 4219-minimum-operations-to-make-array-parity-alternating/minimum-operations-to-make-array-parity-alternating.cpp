class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int k = nums.size();

        // {value, list_index, element_index}
        priority_queue<array<int, 3>, vector<array<int, 3>>,
                       greater<array<int, 3>>>
            pq;

        int current_max = INT_MIN;

        for (int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            current_max = max(current_max, nums[i][0]);
        }

        vector<int> range = {INT_MIN, INT_MAX};

        while (pq.size() == k) {

            auto curr = pq.top();
            pq.pop();

            int min_value = curr[0];
            int list_idx = curr[1];
            int elem_idx = curr[2];

            if (current_max - min_value <
                (long long)range[1] - (long long)range[0]) {
                range = {min_value, current_max};
            }

            if (elem_idx + 1 < nums[list_idx].size()) {
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

        int mini = INT_MAX;
        int count1 = 0;
        int count2 = 0;
        int curr = 0;
        vector<vector<int>> solve1;
        vector<vector<int>> solve2;
        for (auto it : nums) {
            if (abs(it) % 2 != curr) {
                count1++;
                vector<int> options;

                if (it > INT_MIN)
                    options.push_back(it - 1);

                if (it < INT_MAX)
                    options.push_back(it + 1);

                solve1.push_back(options);
            } else {
                solve1.push_back({it});
            }
            curr = 1 - curr;
        }
        curr = 1;
        for (auto& jt : nums) {
            if (abs(jt) % 2 != curr) {
                count2++;
                vector<int> options;

                if (jt > INT_MIN)
                    options.push_back(jt - 1);

                if (jt < INT_MAX)
                    options.push_back(jt + 1);

                solve2.push_back(options);
            } else {
                solve2.push_back({jt});
            }
            curr = 1 - curr;
        }

        if (count1 < count2) {

            auto it = smallestRange(solve1);
            return {count1, it[1] - it[0]};
        } else if (count1 > count2) {

            auto it = smallestRange(solve2);
            return {count2, it[1] - it[0]};
        }

        auto it = smallestRange(solve1);
        auto jt = smallestRange(solve2);

        int mini2 = min(it[1] - it[0], jt[1] - jt[0]);

        return {count1, mini2};
    }
};