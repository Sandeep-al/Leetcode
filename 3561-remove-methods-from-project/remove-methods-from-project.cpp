class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n, vector<int>());
        for (auto& it : invocations) {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> vis_methods(n, 0);
        vis_methods[k] = 1;
        queue<int> q;

        q.push(k);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& it : adj[node]) {
                if (!vis_methods[it]) {
                    vis_methods[it] = 1;
                    q.push(it);
                }
            }
        }

        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            if (vis_methods[i]) {
                continue;
            }

            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto& it : adj[node]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(i);
        }

        for (auto& e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!vis_methods[u] && vis_methods[v]) {
                return ans;
            }
        }
        ans = {};
        for (int i = 0; i < n; i++) {
            if (!vis_methods[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};