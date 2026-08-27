class Solution {
public:
    vector<long long>bucket;
    
    vector<int> nums;
    int n;
    long long target=0;
    bool solve(int idx) {
        if (idx == n) {
            return (bucket[0] == target && bucket[1] == target &&
                    bucket[2] == target && bucket[3] == target);
        }

        if (bucket[0] + nums[idx] <= target) {
            bucket[0] += nums[idx];
            if (solve(idx + 1)) {
                return true;
            }
            bucket[0] -= nums[idx];
        }
        if (bucket[1] + nums[idx] <= target) {
            bucket[1] += nums[idx];
            if (solve(idx + 1)) {
                return true;
            }
            bucket[1] -= nums[idx];
        }
        if (bucket[2] + nums[idx] <= target) {
            bucket[2] += nums[idx];
            if (solve(idx + 1)) {
                return true;
            }
            bucket[2] -= nums[idx];
        }
        if (bucket[3] + nums[idx] <= target) {
            bucket[3] += nums[idx];
            if (solve(idx + 1)) {
                return true;
            }
            bucket[3] -= nums[idx];
        }

        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        nums = matchsticks;
        n = nums.size();
        sort(nums.rbegin(), nums.rend());
        long long total = 0;
        bucket.assign(4,0);
        for (auto& it : nums) {
            total += it;
        }

        if (total % 4 != 0) {
            return false;
        }

        target = total / 4;
        return solve(0);
    }
};