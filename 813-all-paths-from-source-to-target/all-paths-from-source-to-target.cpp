class Solution {
public:
    vector<vector<int>> final_ans;
    int n;
    void dfs(vector<vector<int>>& adj, int node, vector<int>& ans) {

        ans.push_back(node);

        if (node == n - 1) {
            final_ans.push_back(ans);
        }

        for (auto& neigh : adj[node]) {

            dfs(adj, neigh, ans);
        }

        ans.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> ans;
        
        dfs(graph, 0, ans);

        return final_ans;
    }
};