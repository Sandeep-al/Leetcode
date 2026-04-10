class Solution {
public:
    vector<vector<int>> final_ans;
    void solve(int k, int n, vector<int>& ans, int prev) {
        if (k == 0) {
            final_ans.push_back(ans);
            return;
        }

        for (int i = prev+1; i <= n; i++) {

            

            ans.push_back(i);
            solve(k - 1, n, ans, i);
            ans.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
        solve(k, n, ans, 0);
        return final_ans;
    }
};