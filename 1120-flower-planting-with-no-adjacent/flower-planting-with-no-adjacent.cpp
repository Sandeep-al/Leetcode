class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        vector<vector<int>> adj(n);
        for (auto& it : paths) {
            adj[it[0] - 1].push_back(it[1] - 1);
            adj[it[1] - 1].push_back(it[0] - 1);
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int col[] = {0, 0, 0, 0};
            for (auto& it : adj[i]) {
                if (ans[it] != 0) {
                    col[ans[it] - 1] = 1;
                }
            }

            for (int x = 0; x < 4; x++) {
                if (!col[x]) {
                    ans[i] = x + 1;
                }
            }
        }

        return ans;
    }
};