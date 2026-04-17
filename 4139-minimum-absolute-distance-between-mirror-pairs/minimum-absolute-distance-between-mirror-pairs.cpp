class Solution {
public:
    int reverse1(int original) {
        long long ans = 0;
        while (original != 0) {
            ans = ans * 10 + (original % 10);
            original = original / 10;
        }
        return (int)ans;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> last_seen;
        int min_dist = INT_MAX;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int current_val = nums[i];
            
            if (last_seen.count(current_val)) {
                min_dist = min(min_dist, i - last_seen[current_val]);
            }

            int rev = reverse1(current_val);
            last_seen[rev] = i;
        }

        return (min_dist == INT_MAX) ? -1 : min_dist;
    }
};