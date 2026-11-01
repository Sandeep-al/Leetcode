class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mini = nums[n / 2];
        int ans = 0;

        for (auto& it : nums) {
            ans += abs(it - mini);
        }

        return ans;
    }
};