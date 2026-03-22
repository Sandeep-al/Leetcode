class Solution {
public:
    // Vectors ko reference (&) se pass kiya taaki memory aur time bache
    bool dfs(int node, vector<int>& pathvis, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        pathvis[node] = 1;

        for(auto &jt : adj[node]) {
            if(!vis[jt]) {
                if(dfs(jt, pathvis, vis, adj) == false) {
                    return false;
                }
            }
            else if(pathvis[jt]) {
                return false; // Cycle detected!
            }
        }

        // Backtracking: Wapas aate waqt current path se node ko hata do
        pathvis[node] = 0;

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        
        // Variable-Length Arrays (VLA) ki jagah standard C++ vectors
        vector<vector<int>> adj(V);
        vector<int> pathvis(V, 0);
        vector<int> vis(V, 0);
        
        for (auto& it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(i, pathvis, vis, adj) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};