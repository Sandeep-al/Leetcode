class Solution {
public:
    int total = 0;
    vector<vector<int>> adj;
    vector<int> subtree;
    vector<int> dp;
    int x;
    void distance(int node, int level, int parent) {

        total += level;

        for (auto& it : adj[node]) {
            if (it != parent) {
                distance(it, level + 1, node);
            }
        }
    }

    int dfs(int node, int parent) {

        int count = 0;

        for (auto& it : adj[node]) {
            if (it != parent) {
                count += dfs(it, node);
            }
        }

        return subtree[node] = 1 + count;
    }
    void reroot(int node, int parent_sum, int parent) {

        dp[node] = parent_sum;

        for (auto& it : adj[node]) {
            if (it != parent) {

                int count1 = subtree[it];
                int count2 = x - count1;

                int curr_sum = parent_sum + count2 - count1;

                reroot(it, curr_sum, node);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        this->x = n;
        adj.resize(n);
        subtree.resize(n);
        dp.resize(n);
        for (auto& it : edges) {

            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        distance(0, 0, -1);
        dfs(0, -1);
        reroot(0, total, -1);

        return dp;
    }
};