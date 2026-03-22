class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int V = numCourses;
        vector<int> adj[V];
        vector<int> indegree(V, 0);
        vector<int> final_ans;
        queue<int>q;

        for (auto& it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();q.pop();
            final_ans.push_back(node);

            for(auto &jt:adj[node]){
                indegree[jt]--;
                if(indegree[jt]==0){
                    q.push(jt);
                }
            }
        }

        if(final_ans.size()<V) return {};
        return final_ans;
    }
};