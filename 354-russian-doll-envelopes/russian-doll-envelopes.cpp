class Solution {
public:
    int LIS(vector<int>& nums) {

        vector<int> temp;
        temp.push_back(nums[0]);
        int n=nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] > temp.back()) {
                temp.push_back(nums[i]);
            } else {
                int idx = lower_bound(temp.begin(), temp.end(), nums[i])- temp.begin();
                temp[idx] = nums[i];
            }
        }

        return temp.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0]) {
                     return a[1] > b[1];
                 }
                 return a[0] < b[0];
             });

        vector<int> nums;

        for (auto& it : envelopes) {
            nums.push_back(it[1]);
        }

        return LIS(nums);
    }
};