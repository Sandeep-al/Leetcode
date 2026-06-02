class Solution {
public:
    // dp[i] represent minimum cost to keep subtree from node i to be alive
    vector<vector<int>> adj;
    vector<int> values;
    
    long long dfs(int node, int parent) {

        long long cost = 0;
        
        for (auto& it : adj[node]) {
            if (it != parent) {
                cost += dfs(it, node);
            }
        }

        if (cost == 0) {
            return values[node];
        } // leaf node case

        return min(1LL * values[node], cost);
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges,
                                          vector<int>& values) {

        this->values = values;
        int n = values.size();
        adj.resize(n);
        for (auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        long long min_cost= dfs(0,-1);
        long long sum=0;
        for(auto &it:values){
            sum+=it;
        }

        return sum-min_cost;
        
    }
};