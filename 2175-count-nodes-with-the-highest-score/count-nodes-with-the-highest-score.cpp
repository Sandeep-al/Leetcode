class Solution {
public:
    int n;
    vector<long long> dp;
    vector<vector<int>> adj;
    long long maxi=LLONG_MIN;
    long long dfs(int node) {

        long long left = 0;
        long long right = 0;

        int x = adj[node].size();

        if (x >= 1) {
            left = dfs(adj[node][0]);
        }
        if (x >= 2) {
            right = dfs(adj[node][1]);
        }
        long long up = n - left - right - 1;

        long long ans = 1;
        if (left != 0) {
            ans *= left;
        }
        if (right != 0) {
            ans *= right;
        }
        if (up != 0) {
            ans *= up;
        }

        dp[node] = ans;
        maxi=max(ans,maxi);

        return 1 + left + right;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        dp.resize(n, 0);
        adj.resize(n);
        for (int i = 1; i < n; i++) {
            adj[parents[i]].push_back(i);
        }
        dfs(0);
        int count=0;

        for(int i=0;i<n;i++){
            if(dp[i]==maxi) count++;
        }

        return count;
    }
};