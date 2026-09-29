class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        map<int, int> mpp;
        for (int i = -1; i >= -50; i--) {
            mpp[i] = 0;
        }
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                mpp[nums[i]]++;
            }

            if (i >= k) {
                if (nums[i - k] < 0) {
                    mpp[nums[i - k]]--;
                }
            }

            if (i >= k - 1) {
                // i have to scan the whole array...decrement x ... the moment
                // it becomes 0 that is our element

                int yo = x;
                int found = 0;
                for (int j = -50; j <= -1; j++) {
                    yo -= mpp[j];
                    if (yo <= 0) {
                        found = j;
                        break;
                    }
                }

                ans.push_back(found);
            }
        }

        return ans;
    }
};