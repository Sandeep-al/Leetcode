class Solution {
public:
    vector<int> toposort(vector<vector<int>>& adj,int V){
        vector<int>indegree(V,0);
        queue<int>q;
        for(auto &it:adj){
            for(auto &jt:it){
                indegree[jt]++;
            }
        }

        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int>final_ans;
        while(!q.empty()){
            int node=q.front();q.pop();
            final_ans.push_back(node);

            for(auto &it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            
        }

        if(final_ans.size()<V) return {};
        return final_ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<vector<int>> adj1(k);
        vector<vector<int>> adj2(k);
        vector<vector<int>>matrix(k,vector<int>(k,0));

        for(auto &it:rowConditions){
            adj1[it[0]-1].push_back(it[1]-1);
        }

        for(auto &it:colConditions){
            adj2[it[0]-1].push_back(it[1]-1);
        }

        vector<int>topo1=toposort(adj1,k);
        vector<int>topo2=toposort(adj2,k);

        if(topo1.size()==0 || topo2.size()==0){
            return {};
        }

        vector<int> posRow(k);
        vector<int> posCol(k);

        
        for(int i = 0; i < k; i++) {
            posRow[topo1[i]] = i;
            posCol[topo2[i]] = i;
        }

        for(int i = 0; i < k; i++) {
            matrix[posRow[i]][posCol[i]] = i + 1; 
        }

        return matrix;

    }
};