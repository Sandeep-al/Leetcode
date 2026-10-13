
class Solution {
public:
    bool visited(vector<int>& nums, int x, int m) {
        int cnt = 1;
        int last = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - last >= x) {
                cnt++;
                last = nums[i];

                if (cnt >= m) return true;
            }
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int lo = 0;
        int hi = position.back() - position[0] + 1;

        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;

            if (visited(position, mid, m)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        return lo;
    }
};
