class Solution {
public:
    int n;
    int target;
    vector<vector<int>> final_ans;
    vector<int> nums;
    void solve(int idx, vector<int>& curr, int curr_sum) {

        if (curr_sum == target) {
            final_ans.push_back(curr);
            return;
        }

        for (int i = idx; i < n; i++) {
            if (nums[i] + curr_sum <= target) {
                curr_sum += nums[i];
                curr.push_back(nums[i]);
                solve(i, curr, curr_sum);
                curr_sum -= nums[i];
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        this->target = target;
        nums = candidates;
        vector<int> curr;
        solve(0, curr, 0);
        return final_ans;
    }
};