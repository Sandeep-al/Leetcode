class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, int node,
             stack<int>& st) {

        vis[node] = 1;

        for (auto it : adj[node]) {

            if (vis[it] == 1)
                return true;

            if (vis[it] == 0) {
                if (dfs(adj, vis, it, st))
                    return true;
            }
        }

        vis[node] = 2;
        st.push(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int V = numCourses;
        stack<int> st;
        vector<vector<int>> adj(V);
        vector<int> vis(V, 0);

        for (auto& it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                if (dfs(adj, vis, i, st)) {
                    return {};
                }
            }
        }

        vector<int> final_ans;
        while (!st.empty()) {
            final_ans.push_back(st.top());
            st.pop();
        }

        return final_ans;
    }
};
