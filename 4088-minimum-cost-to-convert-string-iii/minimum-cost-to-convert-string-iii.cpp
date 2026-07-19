class Solution {
public:
    string source;
    string target;
    vector<vector<string>> rules;
    vector<int> costs;
    int n;
    int dp[5001];
    int check(int start, int len, string replacement, string pattern) {

        string source_sub = source.substr(start, len);
        string target_sub = target.substr(start, len);

        // x->y   //y==replacment
        bool match = true;

        if (source_sub.size() != pattern.size() ||
            target_sub.size() != replacement.size()) {
            return -1;
        }
        int cost = 0;
        for (int i = 0; i < len; i++) {
            if (pattern[i] == source_sub[i]) {
                continue;
            } else if (pattern[i] == '*') {
                cost++;
                continue;
            }

            match = false;
        }

        if (replacement != target_sub)
            match = false;

        if (!match)
            return -1;
        return cost;
    }
    int solve(int idx) {

        if (idx >= n)
            return 0;
        if (dp[idx] != -5) {
            return dp[idx];
        }
        int curr_cost = INT_MAX;

        for (int i = 0; i < rules.size(); i++) {

            auto rule = rules[i];
            string pattern = rule[0];
            string replacement = rule[1];
            int l = pattern.size();

            int this_cost = check(idx, l, replacement, pattern);

            if (this_cost == -1)
                continue;

            this_cost += costs[i];

            int solve_next = solve(idx + l);

            if (solve_next == -1)
                continue;

            curr_cost = min(curr_cost, this_cost + solve_next);
        }

        if (source[idx] == target[idx]) {
            int solve_next = solve(idx + 1);
            if (solve_next != -1) {
                curr_cost = min(curr_cost, solve_next);
            }
        }
        if (curr_cost == INT_MAX) {
            return dp[idx] = -1;
        }

        return dp[idx] = curr_cost;
    }

    int minCost(string source, string target, vector<vector<string>>& rules,
                vector<int>& costs) {
        
        
        if(source==target) return 0;
        this->source = source;
        this->target = target;
        this->rules = rules;
        this->costs = costs;
        n = source.size();
        for(int i=0;i<5001;i++){
            dp[i]=-5;
        }
        int ans = solve(0);
        return ans;
    }
};