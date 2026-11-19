class Solution {
public:
    using pii = pair<int, int>;
    using min_pq = priority_queue<pii, vector<pii>, greater<pii>>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : times) {
            int from = it[0];
            int to = it[1];
            int wt = it[2];

            from--;
            to--;

            adj[from].push_back({to, wt});
        }

        vector<int> dist(n, 1e9);
        dist[k - 1] = 0;

        min_pq pq;

        pq.push({0,k-1});

        while (!pq.empty()) {

            auto [weight, node] = pq.top();
            pq.pop();

            if (weight > dist[node]) continue;
            for (auto& it : adj[node]) {
                int curr_node = it.first;
                int curr_weight = it.second;

                if (weight + curr_weight < dist[curr_node]) {
                    dist[curr_node] = weight + curr_weight;
                    pq.push({weight + curr_weight, curr_node});
                }
            }
        }

        int max_time = 0;
        for (int d : dist) {
            if (d == 1e9) return -1; 
            max_time = max(max_time, d);
        }

        return max_time;
    }
};