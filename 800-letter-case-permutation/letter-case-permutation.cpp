class Solution {
public:
    int n;
    vector<string> final_ans;
    string grid;
    void solve(string& s) {
        if (s.size() == n) {
            final_ans.push_back(s);
            return;
        }

        int x = s.size();

        char ch = grid[x];

        if (isdigit(ch)) {
            s.push_back(ch);
            solve(s);
            s.pop_back();
        } else {
            char ch1;
            if (islower(ch))
                ch1 = toupper(ch);
            else if (isupper(ch))
                ch1 = tolower(ch);

            s.push_back(ch);
            solve(s);
            s.pop_back();

            s.push_back(ch1);
            solve(s);
            s.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        n = s.size();
        grid = s;
        string x = "";
        solve(x);
        return final_ans;
    }
};