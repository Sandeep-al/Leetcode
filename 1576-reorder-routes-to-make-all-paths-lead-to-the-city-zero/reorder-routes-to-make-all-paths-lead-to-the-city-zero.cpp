class Solution {
public:
    int dfs(int node, int parent, vector<vector<pair<int, int>>>& adj) {
        int current_total = 0;
        
        for (auto& it : adj[node]) {
            int neighbor = it.first;
            int cost = it.second;
            
            if (neighbor != parent) {
                current_total += cost + dfs(neighbor, node, adj);
            }
        }
        
        return current_total;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : connections) {
            adj[it[0]].push_back({it[1], 1});
            adj[it[1]].push_back({it[0], 0});
        }
        
        return dfs(0, -1, adj);
    }
};