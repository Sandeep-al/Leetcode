class Solution {
public:
    vector<string> dp;
    string reverse(string x) {
        int yo = x.size() - 1;
        int go = 0;

        while (go < yo) {
            swap(x[yo], x[go]);
            go++;
            yo--;
        }

        return x;
    }
    string inverse(string x) {
        for (int i = 0; i < x.size(); i++) {
            if (x[i] == '1')
                x[i] = '0';
            else
                x[i] = '1';
        }

        return x;
    }

    string solve(int i) {

        if (i == 1)
            return "0";

        if (dp[i] != "")
            return dp[i];

        return dp[i] = solve(i - 1) + "1" + reverse(inverse(solve(i - 1)));
    }
    // char findKthBit(int n, int k) {

    //     dp.assign(n + 1, "");
    //     string ans = solve(n);
    //     return ans[k - 1];
    // }

    // Memoization code
    // char findKthBit(int n, int k) {

    //     dp.assign(n + 1, "");
    //     dp[1] = "0";

    //         for (int i = 2; i <= n; i++) {
    //         dp[i] = dp[i - 1] + "1" + reverse(inverse(dp[i - 1]));
    //     }

    //     return dp[n][k - 1];
    // }

    // space optimization
    char findKthBit(int n, int k) {

        string prev = "0";
        string curr = "";
        for (int i = 2; i <= n; i++) {
            curr = prev + "1" + reverse(inverse(prev));
            prev=curr;
        }

        return prev[k - 1];
    }
};