class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int k = nums.size();

        // {value, list_index, element_index}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        int current_max = INT_MIN;

        for (int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            current_max = max(current_max, nums[i][0]);
        }

        vector<int> range = {-1000000, 1000000};

        while (true) {

            auto curr = pq.top();
            pq.pop();

            int min_value = curr[0];
            int list_idx = curr[1];
            int elem_idx = curr[2];

            if (current_max - min_value < range[1] - range[0]) {
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
};