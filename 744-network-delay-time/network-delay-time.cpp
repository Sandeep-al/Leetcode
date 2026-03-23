class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        vector<int>dist(n,INT_MAX);
        dist[k-1]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(auto &it:times){
            adj[it[0]-1].push_back({it[1]-1,it[2]});
        }
        
        pq.push({0,k-1});

        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            int node=it.second;
            int wt=it.first;
            if(wt > dist[node]) continue;
            for(auto &jt:adj[node]){
                if(dist[jt.first]>jt.second+wt){
                    dist[jt.first]=jt.second+wt;
                    pq.push({jt.second+wt,jt.first});
                }
            }
        }

        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX) return -1;
            ans=max(ans,dist[i]);
        }

        return ans;
    }
};