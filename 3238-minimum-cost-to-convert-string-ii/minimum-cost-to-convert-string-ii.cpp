class Solution {
public:
    const long long INF = 4e18;
    vector<vector<long long>> dist;
    string source;
    string target;
    int n;
    long long dp[1001];
    unordered_map<string, int> mpp;

    long long solve(int idx) {

        if (idx >= n)
            return 0;

        if(dp[idx]!=-2) return dp[idx];
        long long mini = INF;

        for (auto& it : mpp) {

            string pattern = it.first;
            int node1 = it.second;

            int len = pattern.size();

            string curr_source = source.substr(idx, len);
            string curr_target = target.substr(idx, len);

            if (curr_source != pattern)
                continue;

            if (mpp.find(curr_target) == mpp.end())
                continue;

            int node2 = mpp[curr_target];

            long long curr_cost = dist[node1][node2];

            if (curr_cost == INF)
                continue;

            long long next_solve = solve(idx + len);

            if (next_solve != INF) {
                mini = min(mini, next_solve + curr_cost);
            }
        }

        
        if (source[idx] == target[idx]) {

            long long next_solve = solve(idx + 1);

            if (next_solve != INF) {
                mini = min(mini, next_solve);
            }
        }

        return dp[idx]=mini;
    }

    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        if (source == target)
            return 0;   

        for(int i=0;i<1001;i++){
            dp[i]=-2;
        }

        n = source.size();
        this->source = source;
        this->target = target;

        int id = 0;

        for (auto& it : original) {
            if (mpp.find(it) == mpp.end())
                mpp[it] = id++;
        }

        for (auto& it : changed) {
            if (mpp.find(it) == mpp.end())
                mpp[it] = id++;
        }

        int m = mpp.size();

        dist.assign(m, vector<long long>(m, INF));

        for (int i = 0; i < m; i++)
            dist[i][i] = 0;

     
        for (int i = 0; i < changed.size(); i++) {

            int node1 = mpp[original[i]];
            int node2 = mpp[changed[i]];

            long long edge_wt = cost[i];

            dist[node1][node2] = min(dist[node1][node2], edge_wt);
        }

        
        for (int k = 0; k < m; k++) {

            for (int i = 0; i < m; i++) {

                if (dist[i][k] == INF)
                    continue;

                for (int j = 0; j < m; j++) {

                    if (dist[k][j] == INF)
                        continue;

                    dist[i][j] =
                        min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        long long ans = solve(0);

        if (ans == INF)
            return -1;

        return ans;
    }
};