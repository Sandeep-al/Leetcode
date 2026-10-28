class Solution {
public:
    void dfs(int& mini, int node, vector<vector<pair<int, int>>>& adj,
             vector<int>& vis) {

        vis[node] = 1;

        for (auto& it : adj[node]) {

            int neigh = it.first;
            int wt = it.second;
            mini = min(mini, wt);
            if (!vis[neigh]) {

                dfs(mini, neigh, adj, vis);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> vis(n);

        for (auto& it : roads) {
            int from = it[0] - 1;
            int to = it[1] - 1;
            int wt = it[2];

            adj[from].push_back({to, wt});
            adj[to].push_back({from, wt});
        }

        int mini = INT_MAX;

        dfs(mini, 0, adj, vis);
        return mini;
    }
};