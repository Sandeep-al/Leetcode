class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<vector<int>>& graph,
             vector<int>& dp) {

        vis[node] = 1;
        bool ans = true;
        for (auto& it : graph[node]) {

            if (vis[it] == 1) {
                return dp[node]=false;
            }

            if (vis[it] == 0) {
                ans = ans & dfs(it, vis, graph, dp);
            }

            else if (vis[it] == 2) {
                if (dp[it] == 0) { 
                    return dp[node] = false; 
                }
            }
        }
        vis[node] = 2;
        return dp[node] = ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> dp(n, 1);
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs(i, vis, graph, dp);
            }
        }

        vector<int> final_ans;
        for (int i = 0; i < n; i++) {
            if (dp[i] == 1) {
                final_ans.push_back(i);
            }
        }

        return final_ans;
    }
};