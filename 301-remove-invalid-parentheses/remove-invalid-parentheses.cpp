class Solution {
public:
    unordered_set<string> final_ans;
    string s;
    int n;
    void solve(int idx, string& temp, int curr_open, int extra_close,
               int extra_open) {

        // base case

        if (idx == n) {
            if (curr_open == 0 && extra_close == 0 && extra_open == 0) {
                final_ans.insert(temp);
               
            }

            return;
        }
        // picking
        // u can only pick iff open u can pick any time
        //  close u can only pick iff there is open>0
        if (s[idx] != '(' && s[idx] != ')') {
            temp.push_back(s[idx]);
            solve(idx + 1, temp, curr_open, extra_close, extra_open);
            temp.pop_back();
        }
        if (s[idx] == '(') {
            temp.push_back(s[idx]);
            solve(idx + 1, temp, curr_open + 1, extra_close, extra_open);
            temp.pop_back();
        }
        if (s[idx] == ')' && curr_open > 0) {
            temp.push_back(s[idx]);
            solve(idx + 1, temp, curr_open - 1, extra_close, extra_open);
            temp.pop_back();
        }

        // skipping case

        if (s[idx] == '(' && extra_open > 0) {
            solve(idx + 1, temp, curr_open, extra_close, extra_open - 1);
        }
        if (s[idx] == ')' && extra_close > 0) {
            solve(idx + 1, temp, curr_open, extra_close - 1, extra_open);
        }
    }
    vector<int> find_min_removals(string s) {
        int open = 0;
        int extra_close = 0;

        for (auto& it : s) {
            if (it == '(') {
                open++;
            } else if (it == ')' && open > 0) {
                open--;
            } else if (it == ')') {
                extra_close++;
            }
        }

        return {open, extra_close};
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<int> x = find_min_removals(s);
        this->s = s;
        n = s.size();
        int extra_open = x[0];
        int extra_close = x[1];
        string z = "";
        solve(0, z, 0, extra_close, extra_open);
        vector<string> final_final_ans;
        for (auto& it : final_ans) {
            final_final_ans.push_back(it);
        }
        return final_final_ans;
    }
};