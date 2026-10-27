class Solution {
public:
    void dfs(int node,int parent, int& total, vector<vector<pair<int, int>>>& adj) {

        for (auto& it : adj[node]) {
            if(it.first!=parent){
            total += it.second;
            dfs(it.first,node,total, adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : connections) {
            int from = it[0];
            int to = it[1];
            adj[it[0]].push_back({it[1], 1});
            adj[it[1]].push_back({it[0], 0});
        }
        int total=0;
        dfs(0,-1,total,adj);
        return total;
    }
};