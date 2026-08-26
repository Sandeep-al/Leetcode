class Solution {
public:
    vector<string> final_ans;
    string curr = "";
    int n;

    void solve(int idx, int open) {
        if (idx == 2 * n) {
            if (open == 0) {
                final_ans.push_back(curr);
            }
            return;
        }

        if (open > 0) {
            curr.push_back(')');
            solve(idx + 1, open - 1);
            curr.pop_back();
        }

        if (open < n) {
            curr.push_back('(');
            solve(idx + 1, open + 1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        this->n = n;
        solve(0, 0);
        return final_ans;
    }
};