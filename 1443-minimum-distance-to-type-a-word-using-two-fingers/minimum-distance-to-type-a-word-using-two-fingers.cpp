class Solution {
public:
    vector<vector<vector<int>>> memo;
    int n;
    string word;

    pair<int, int> getC(int f) {
        return {f / 6, f % 6};
    }

    int solve(int f1, int f2, int idx) {
        if (idx == n)
            return 0;

        if (memo[idx][f1][f2] != -1) 
            return memo[idx][f1][f2];

        int mini = 1e9;
        int curr = word[idx] - 'A';

        if (f1 == 26) {
            mini = min(mini, solve(curr, f2, idx + 1));
        }
        if (f2 == 26) {
            mini = min(mini, solve(f1, curr, idx + 1));
        }

        if (curr == f1 || curr == f2) {
            mini = min(mini, solve(f1, f2, idx + 1));
        }

        if (f1 != 26) {
            auto cord1 = getC(curr);
            auto cord2 = getC(f1);
            int dist1 = abs(cord1.first - cord2.first) + abs(cord1.second - cord2.second);
            mini = min(mini, dist1 + solve(curr, f2, idx + 1));
        }
        
        if (f2 != 26) {
            auto cord1 = getC(curr);
            auto cord3 = getC(f2);
            int dist2 = abs(cord1.first - cord3.first) + abs(cord1.second - cord3.second);
            mini = min(mini, dist2 + solve(f1, curr, idx + 1));
        }

        return memo[idx][f1][f2] = mini;
    }

    int minimumDistance(string word) {
        this->word = word;
        this->n = word.size();
        
        memo.assign(n, vector<vector<int>>(27, vector<int>(27, -1)));

        return solve(26, 26, 0);
    }
};