class Solution {
public:
    vector<string> ans;
    int k;
    int n;
    string x = "abc";
    void solve(int last, int i, string& yo) {
        if (i == n) {
            ans.push_back(yo);
            return;
        }

        for (int idx = 0; idx < 3; idx++) {
            if (idx != last) {
                yo.push_back(x[idx]);
                solve(idx, i + 1, yo);
                yo.pop_back();
            }
        }
        return;
    }
    string getHappyString(int n, int k) {
        this->n = n;
        this->k = k;
        string yo = "";
        solve(-1, 0, yo);

        if (ans.size() < k)
            return "";
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};