class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
             vector<int>& clr, int& possible, int color) {

        if (!possible)
            return;
        vis[node] = 1;
        clr[node] = color;

        for (auto& it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, clr, possible, 1 - color);
            } else if (vis[it] && clr[it] == color) {
                possible = 0;
            }
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> adj(n);
        for (auto& it : dislikes) {
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }

        vector<int> vis(n, 0);
        vector<int> clr(n, 0);
        int possible = 1;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, clr, possible, 0);
            }
        }

        return possible;
    }
};