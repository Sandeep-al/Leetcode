class Solution {
public:
    vector<int> vis;
    vector<vector<int>>adj;
    void dfs2(int node, int& total_degree,int &nodes) {
        vis[node] = true;
        nodes++;
        total_degree +=
            adj[node].size(); 
        for (int child : adj[node]) {
            if (!vis[child]) {
                dfs2(child, total_degree,nodes);
            }
        }
    }
    void dfs(int node) {
        vis[node] = 1;

        for (auto neighbour : adj[node]) {
            if (!vis[neighbour]) {
                dfs(neighbour);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> components;
        vis.assign(n, 0);
        adj.assign(n,{});

        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i);
                components.push_back(i);
            }
        }
        int total=0;
        for(auto &it:components){
            vis.assign(n, 0);
            int degree=0;
            int nodes=0;
            dfs2(it,degree,nodes);
            degree=degree/2;
            if(degree== nodes*(nodes-1)/2){
                total++;
            }
        }
        return total;
    }
};