class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        queue<pair<int, pair<int, int>>> q; // no of stops,node,cost
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : flights) {
            int from = it[0];
            int to = it[1];
            int wt = it[2];
            adj[from].push_back({to, wt});
        }
        vector<int> dist(n, INT_MAX);
        dist[src]=0;
        q.push({0, {src, 0}});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int node = it.second.first;
            int wt = it.second.second;
            int steps = it.first;
            if (steps > k) continue;

            for (auto& jt : adj[node]) {
                if (dist[jt.first] > jt.second + wt) {
                    dist[jt.first] = jt.second + wt;
                    q.push({steps + 1, {jt.first, dist[jt.first]}});
                }
            }
        }

        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};