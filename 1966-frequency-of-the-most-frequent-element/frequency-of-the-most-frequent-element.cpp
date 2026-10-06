class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxi = 0;

        int l = 0;
        long long total = 0;
        

        for (int r = 0; r < n; r++) {
            total += nums[r];
            

            while ((1LL*nums[r]*(r-l+1)-total) > k) {
                total -= nums[l ] ;
                l++;
            }
            maxi = max(maxi, r - l + 1);
        }

        return maxi;
    }
};