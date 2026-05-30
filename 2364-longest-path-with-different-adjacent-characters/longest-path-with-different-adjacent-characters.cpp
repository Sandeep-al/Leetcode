class Solution {
public:
    string x;
    int final_ans = 0;
    int dfs(vector<vector<int>>& adj, int curr) {

        int n = adj[curr].size();
        vector<int> contributions(n, 0);

        for (int i = 0; i < n; i++) {

            int node = adj[curr][i];
            contributions[i] = dfs(adj, node);
        }

        vector<int> dz(n, 0);

        int maxi1 = 0;
        int maxi2 = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++) {

            int node = adj[curr][i];
            if (x[curr] != x[node]) {
                dz[i] = contributions[i];
            }

            if (dz[i] >= maxi1) {
                maxi2 = maxi1;
                maxi1 = dz[i];
            } else if (dz[i] > maxi2 ) {
                maxi2 = dz[i];
            }
        } // or simply make contributions[i]=0 on equality condition

        final_ans = max(final_ans, maxi1 + maxi2 + 1);
        return maxi1 + 1;
    }
    int longestPath(vector<int>& parent, string s) {

        int n = parent.size();
        vector<vector<int>> adj(n);
        this->x = s;
        for (int i = 1; i < n; i++)
            adj[parent[i]].push_back(i);

        dfs(adj, 0);

        return final_ans;
    }
};