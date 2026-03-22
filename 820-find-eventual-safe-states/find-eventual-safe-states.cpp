class Solution {
public:
    bool dfs(vector<int>& safe, vector<int>& vis, vector<int>&pathvis,
             vector<vector<int>>& graph, int node) {
        vis[node] = 1;
        pathvis[node] = 1;

        for (auto& it : graph[node]) {
            if (!vis[it]) {
                if (dfs(safe, vis, pathvis, graph, it) == false) {
                    return false;
                }
            } else if (pathvis[it]) {
                return false;
            }
        }

        pathvis[node]=0;
        safe[node] = 1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> safe(V, 0);
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i] && dfs(safe,vis,pathvis,graph,i)) {
                safe[i] = 1;
            }
        }

        vector<int> final_ans;
        for (int i = 0; i < V; i++) {
            if (safe[i]) {
                final_ans.push_back(i);
            }
        }

        return final_ans;
    }
};