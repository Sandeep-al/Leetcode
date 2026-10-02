class Solution {
public:
    int totalFruit(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        int l = 0;
        int ans = 0;
        
        for (int r = 0; r < n; r++) {
            mpp[nums[r]]++;
            

            while (mpp.size() > 2) {
                mpp[nums[l]]--;
                
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++;
            }

            ans = max(ans,r-l+1);
        }

        return ans;
    }
};