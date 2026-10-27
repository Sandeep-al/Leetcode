class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node, vector<int>& vis, int& total,
             int& total_nodes) {

        vis[node] = 1;
        total_nodes++;
        total += adj[node].size();

        for (int& x : adj[node]) {
            if (!vis[x]) {
                dfs(adj, x, vis, total, total_nodes);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        for (auto& it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int count = 0;
        int extra_edges = 0;
        for (int i = 0; i < n; i++) {
            // new connected component
            if (!vis[i]) {
                int total_edge = 0;
                int total_nodes = 0;
                dfs(adj, i, vis, total_edge, total_nodes);
                total_edge /= 2;

                int extra = total_edge - total_nodes + 1;

                extra_edges += extra;
                count++;

                // now we need total_edge== total_nodes-1
            }
        }

        if (extra_edges >= count - 1) {
            return count - 1;
        }

        return -1;
    }
};