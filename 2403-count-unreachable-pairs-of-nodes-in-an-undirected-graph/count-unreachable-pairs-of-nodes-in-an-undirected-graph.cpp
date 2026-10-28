class Solution {
public:
    void dfs(int& size, int node, vector<vector<int>>& adj, vector<int>& vis) {

        vis[node] = 1;
        size++;

        for (auto& neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs(size, neigh, adj, vis);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {

        vector<int> vis(n, 0);
        vector<int> get;
        vector<vector<int>>adj(n);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int size = 0;
                dfs(size, i, adj, vis);
                get.push_back(size);
            }
        }

        int yo = get.size();
        vector<long long> prefix(yo, 1);
        prefix[0] = get[0];

        for (int i = 1; i < yo; i++) {
            prefix[i] = prefix[i - 1] + get[i];
        }

        long long ans = 0;
        for (int i = 0; i < yo; i++) {
            int curr = get[i];
            // i+1.....n-1
            if (i + 1 < yo) {

                int before =prefix[i];
                int after = prefix[yo-1];

                int total = after - before;
                ans += 1LL * curr * total;
            }
        }

        return ans;
    }
};