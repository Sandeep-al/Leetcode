class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        
        unordered_map<int, int> mpp;
        int l = 0;
        int n = nums.size();
        int pairs = 0;
        long long count = 0;
        for (int r = 0; r < n; r++) {
            int curr = mpp[nums[r]];

            pairs -=(curr * (curr - 1)) / 2;
            pairs += (curr * (curr + 1)) / 2;

            mpp[nums[r]]++;

            while (pairs >= k) {
                int curr = mpp[nums[l]];

                pairs -= (curr * (curr - 1)) / 2;
                pairs += ((curr - 1) * (curr - 2)) / 2;

                mpp[nums[l]]--;
                l++;
            }

            count += l;
        }

        return count;
    }
};