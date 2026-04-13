class Solution {
    vector<vector<int>> memo;
    vector<int> prefix;
    int K;

    int solve(int i, int j) {
        if (i == j) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        
        int res = 1e9;
        for (int m = i; m < j; m += K - 1) {
            res = min(res, solve(i, m) + solve(m + 1, j));
        }
        
        if ((j - i) % (K - 1) == 0) {
            res += prefix[j + 1] - prefix[i];
        }
        
        return memo[i][j] = res;
    }

public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) return -1;
        
        K = k;
        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }
        
        memo.assign(n, vector<int>(n, -1));
        return solve(0, n - 1);
    }
};