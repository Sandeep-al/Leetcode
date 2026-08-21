class Solution {
public:
    vector<vector<int>> ans;
    vector<int>nums;
    int n;
    void solve(vector<int>& curr, int i) {
        if (i == n) {
            ans.push_back(curr);
            return;
        }

        solve(curr, i + 1);
        curr.push_back(nums[i]);
        solve(curr, i + 1);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        this->n = nums.size();
        vector<int> curr;
        this->nums=nums;
        solve(curr, 0);
        return ans;
    }
};