class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node, vector<int>& vis) {

        vis[node] = 1;

        for (auto& neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs(adj, neigh, vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);

        for (auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        dfs(adj, source, vis);

        if (vis[destination]) {
            return true;
        }

        return false;
    }
};