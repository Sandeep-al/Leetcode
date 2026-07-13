class Solution {
public:
    int solve(int nodes, vector<int>& memo) {

        if (nodes <= 1) {
            return 1;
        }

        if (memo[nodes] != -1) {
            return memo[nodes];
        }

        int ans = 0;

        for (int i = 1; i <= nodes; i++) {
            int leftNodes = i - 1;
            int rightNodes = nodes - i;

            int leftTrees = solve(leftNodes, memo);
            int rightTrees = solve(rightNodes, memo);

            ans += (leftTrees * rightTrees);
        }

        return memo[nodes] = ans;
    }

    int numTrees(int n) {

        vector<int> memo(n + 1, -1);
        return solve(n, memo);
    }
};