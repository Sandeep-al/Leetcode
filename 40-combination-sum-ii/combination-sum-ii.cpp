class Solution {
public:
    int n;
    int target;
    vector<vector<int>> final_ans;
    vector<int> nums;
    vector<int> used;
    void solve(int idx, vector<int>& curr, int curr_sum) {

        if (curr_sum == target) {
            final_ans.push_back(curr);
            return;
        }
        
        for (int i = idx; i < n; i++) {

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            if (nums[i] + curr_sum <= target) {
                curr_sum += nums[i];
                curr.push_back(nums[i]);
                used[i] = 1;
                solve(i + 1, curr, curr_sum);
                curr_sum -= nums[i];
                curr.pop_back();
                used[i] = 0;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        this->target = target;
        nums = candidates;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        used.assign(n, 0);
        solve(0, curr, 0);
        return final_ans;
    }
};