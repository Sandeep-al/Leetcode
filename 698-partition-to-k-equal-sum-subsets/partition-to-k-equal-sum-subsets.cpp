class Solution {
public:
    int target;
    int k;
    int n;
    vector<int> buckets;
    vector<int> nums;
    bool solve(int idx) {
        if (idx == n)
            return true;
        // can i put this number in any of the bucket
        for (int i = 0; i < k; i++) {
            int curr = buckets[i];
            if (curr + nums[idx] <= target) {
                buckets[i] += nums[idx];

                if (solve(idx + 1))
                    return true;

                buckets[i] -= nums[idx];
            }

            if (buckets[i] == 0)
                break;
        }

        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        this->k = k;
        this->nums = nums;
        n = nums.size();
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        if (sum % k == 0)
            target = sum / k;
        else
            return false;

        buckets.assign(k, 0);
        return solve(0);
    }
};