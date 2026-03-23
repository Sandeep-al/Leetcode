class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({0, {0, 0}});

        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));

        distance[0][0] = 0;

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int i = it.second.first;
            int j = it.second.second;

            for (auto& jt : directions) {
                int temp_i = i + jt[0];
                int temp_j = j + jt[1];

                if (temp_i >= 0 && temp_i < m && temp_j >= 0 && temp_j < n) {
                    int val = heights[temp_i][temp_j];
                    int newEffort = max(abs(heights[i][j] - val), wt);

                    if (newEffort < distance[temp_i][temp_j]) {
                        distance[temp_i][temp_j] = newEffort;
                        pq.push({newEffort, {temp_i, temp_j}});
                    }
                }
            }
        }

        return distance[m - 1][n - 1];
    }
};