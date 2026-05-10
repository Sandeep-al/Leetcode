class Solution {
public:
    vector<int> nums;
    int n;
    vector<vector<int>> final_ans;
    void solve(vector<int>& curr, int last) {
        if (curr.size() >= 2) {
            final_ans.push_back(curr);
            if (curr.size() == n)
                return;
        }
        unordered_set<int> used;
        int last_added = last == -1 ? INT_MIN : nums[last];
        for (int i = last + 1; i < n; i++) {

            if (used.count(nums[i]))
                continue;

            if (nums[i] >= last_added) {
                used.insert(nums[i]);
                curr.push_back(nums[i]);
                solve(curr, i);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        vector<int> curr;
        solve(curr, -1);
        return final_ans;
    }
};