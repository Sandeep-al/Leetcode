class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++) {
            adj[arr[i]].push_back(i);
        }

        vector<int> vis(n, 0);
        vector<int> level(n, -1);

        queue<int> pq;

        pq.push(0);

        vis[0] = 1;
        level[0] = 0;

        while (!pq.empty()) {

            int node = pq.front();
            pq.pop();

            if (node == n - 1)
                return level[node];

            // same value jumps
            for (auto it : adj[arr[node]]) {

                if (!vis[it]) {

                    vis[it] = 1;

                    pq.push(it);

                    level[it] = level[node] + 1;
                }
            }

            // IMPORTANT
            adj[arr[node]].clear();

            // node - 1
            if (node > 0 && !vis[node - 1]) {

                vis[node - 1] = 1;

                pq.push(node - 1);

                level[node - 1] = level[node] + 1;
            }

            // node + 1
            if (node < n - 1 && !vis[node + 1]) {

                vis[node + 1] = 1;

                pq.push(node + 1);

                level[node + 1] = level[node] + 1;
            }
        }

        return level[n - 1];
    }
};