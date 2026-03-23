class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int>st;
        for(auto &it:restricted){
            st.insert(it);
        }
        vector<vector<int>>adj(n);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        vis[0]=1;

        queue<int>q;
        q.push(0);

        while(!q.empty()){
            int node=q.front();q.pop();

            for(auto &jt:adj[node]){
                if(vis[jt]==0 && st.find(jt)==st.end()){
                    vis[jt]=1;
                    q.push(jt);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]) count++;
        }

        return count;
    }
};