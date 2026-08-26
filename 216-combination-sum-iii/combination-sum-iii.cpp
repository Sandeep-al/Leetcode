class Solution {
public:
    int target;
    int n;
    vector<vector<int>> final_ans;
    int used[11];
    vector<int> curr;
    void solve(int start, int idx, int curr_sum) {
        if (idx == n) {
            if (curr_sum == target) {
                final_ans.push_back(curr);
                return;
            }
            return;
        }

        for (int i = start; i < 10; i++) {
            if (i + curr_sum <= target && !used[i]) {
                used[i] = 1;
                curr.push_back(i);
                solve(i + 1, idx + 1, curr_sum + i);
                curr.pop_back();
                used[i] = 0;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        this->n = k;
        this->target = n;
        memset(used, 0, sizeof(used));
        solve(1, 0, 0);
        return final_ans;
    }
};