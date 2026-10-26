class Solution {
public:
     void dfs(vector<vector<int>>& adj, int node, vector<int>& vis) {

        vis[node] = 1;

        for (auto& neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs(adj, neigh, vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>vis(n,0);
        int count=0;
        dfs(rooms,0,vis);

        for(int i=0;i<n;i++){
            count+=vis[i];
        }

        return count==n;
    }
};