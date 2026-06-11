class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    vector<vector<int>> adj;
    vector<vector<int>> dp;

    int solve(int n, int parity) {
        if (n == 0)
            return parity == 0;

        if (dp[n][parity] != -1)
            return dp[n][parity];

        if (parity == 1) {
            return dp[n][1] = (1LL * solve(n - 1, 0) + solve(n - 1, 1)) % MOD;
        }

        return dp[n][0] = (1LL * solve(n - 1, 1) + solve(n - 1, 0)) % MOD;
    }

    int maxdepth(int node, int parent) {
        int maxi = 0;

        for (int nxt : adj[node]) {
            if (nxt != parent) {
                maxi = max(maxi, maxdepth(nxt, node));
            }
        }

        return 1 + maxi;
    }

    int modPow(long long a, long long b) {
        long long res = 1;
        long long MOD = 1e9 + 7;

        while (b > 0) {
            if (b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return (int)res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int nodes = edges.size() + 1;

        adj.assign(nodes, {});
        dp.assign(nodes + 1, vector<int>(2, -1));

        for (auto& e : edges) {
            adj[e[0] - 1].push_back(e[1] - 1);
            adj[e[1] - 1].push_back(e[0] - 1);
        }

        int maxi = maxdepth(0, -1) - 1;
        return modPow(2, maxi - 1);
        // return solve(maxi, 1);

        
    }
};