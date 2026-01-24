class Solution {
public:
    vector<int> nums;
    vector<char> ops;
    vector<vector<vector<int>>> dp;
    void tokenize(string& s, vector<int>& nums, vector<char>& ops) {
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else {
                nums.push_back(num);
                ops.push_back(c);
                num = 0;
            }
        }
        nums.push_back(num);
    }
    vector<int> solve(int i, int j) {
        if (!dp[i][j].empty())
            return dp[i][j];

        if (i == j) {
            return dp[i][j] = {nums[i]};
        }

        vector<int> res;

        for (int k = i; k < j; k++) {
            vector<int> left = solve(i, k);
            vector<int> right = solve(k + 1, j);

            for (int a : left) {
                for (int b : right) {
                    if (ops[k] == '+')
                        res.push_back(a + b);
                    else if (ops[k] == '-')
                        res.push_back(a - b);
                    else
                        res.push_back(a * b);
                }
            }
        }

        return dp[i][j] = res;
    }

    vector<int> diffWaysToCompute(string expression) {
        tokenize(expression, nums, ops);
        int n = nums.size();
        dp.resize(n, vector<vector<int>>(n));
        return solve(0, n - 1);
    }
};
