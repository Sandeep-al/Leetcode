class Solution {
public:
    vector<vector<int>> ans;
    vector<int> nums;
    int n;
    void solve(vector<int>& curr, int i) {
        if (i == n) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        solve(curr, i + 1);
        curr.pop_back();

        while (i + 1 < n && nums[i] == nums[i + 1]) {
            i++;
        }
        solve(curr, i + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        this->n = nums.size();
        vector<int> curr;
        sort(nums.begin(), nums.end());
        this->nums = nums;
        solve(curr, 0);
        return ans;
    }
};