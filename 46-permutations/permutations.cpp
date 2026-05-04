class Solution {
public:
    int n;
    unordered_set<int> vis;
    vector<vector<int>> ans;
    vector<int>nums;
    void solve(vector<int>& curr) {
        if (curr.size() == n) {
            ans.push_back(curr);
            curr.empty();
            return;
        }

        for (int i = 0; i < n; i++) {
            if (vis.count(nums[i])==0) {
                curr.push_back(nums[i]);
                vis.insert(nums[i]);
                solve(curr);
                curr.pop_back();
                vis.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) { 
        this->nums=nums;
        n = nums.size(); 
        vector<int>curr;
        solve(curr);
        return ans;
        
        
    }
};