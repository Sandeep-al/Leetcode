class Solution {
public:
    vector<vector<int>> twosum(vector<int>& nums, int l, int r, long long target) {

        vector<vector<int>> ans;
        while (l < r) {

            if ((long long)nums[l] + nums[r] == target) {
                ans.push_back({nums[l], nums[r]});

                l++;
                r--;

                while (l < r && nums[l] == nums[l - 1])
                    l++;

                while (l < r && nums[r] == nums[r + 1])
                    r--;
            } else if ((long long)nums[l] + nums[r] > target) {
                r--;
            } else {
                l++;
            }
        }

        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums, long long target, int l, int n) {

        vector<vector<int>> final_ans;
        for (int i = l; i < n - 2; i++) {

            if (i > l && nums[i] == nums[i - 1]) {
                continue;
            }

            int curr = nums[i];
            long long tar = target - curr;

            auto ans = twosum(nums, i + 1, n - 1, tar);

            for (auto& it : ans) {
                vector<int> temp;
                temp.push_back(nums[i]);

                for (auto& jt : it) {
                    temp.push_back(jt);
                }

                final_ans.push_back(temp);
            }
        }

        return final_ans;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> final_ans;
        int n = nums.size();

        for (int i = 0; i < n - 3; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            long long t = (long long)target - nums[i];

            auto ans = threeSum(nums, t, i + 1, n);

            for (auto& it : ans) {
                vector<int> temp;
                temp.push_back(nums[i]);

                for (auto& jt : it) {
                    temp.push_back(jt);
                }

                final_ans.push_back(temp);
            }
        }

        return final_ans;
    }
};