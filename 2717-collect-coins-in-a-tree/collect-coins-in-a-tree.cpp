class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {

        int n = coins.size();
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            degree[it[0]]++;
            degree[it[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (degree[i] == 1 && coins[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            degree[node] = 0;

            for (auto& nei : adj[node]) {

                if (degree[nei] == 0)
                    continue;

                degree[nei]--;

                if (degree[nei] == 1 && coins[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        
        int x = 2;
        queue<int> q1;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1)
                q1.push(i);
        }
        while (x > 0) {

            x--;
            int z = q1.size();

            for (int i = 0; i < z; i++) {

                int node = q1.front();
                q1.pop();

                degree[node]=0;

                for (auto& it : adj[node]) {
                    if (degree[it] == 0) {
                        continue;
                    }

                    degree[it]--;
                    if (degree[it] == 1) {
                        q1.push(it);
                    }
                }
            }
        }

        int count=0;
        for(int i=0;i<n;i++){
            if(degree[i]>0) count++;
        }
        
        if(count<2) return count;
        return (count-1)*2;
    }
};