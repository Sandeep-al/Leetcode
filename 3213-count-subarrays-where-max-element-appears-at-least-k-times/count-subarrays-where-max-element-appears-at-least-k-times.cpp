class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = 0;
        for (auto& it : nums) {
            maxi = max(maxi, it);
        }

        int n = nums.size();
        int l = 0;
        long long count = 0;
        int total = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxi) {
                total++;
            }

            while (total >= k) {
                if (nums[l] == maxi) {
                    total--;
                }
                l++;
            }
            count += l;
        }
        return count;
    }
};