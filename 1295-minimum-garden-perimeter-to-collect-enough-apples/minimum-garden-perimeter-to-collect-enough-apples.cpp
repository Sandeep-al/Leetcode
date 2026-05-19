class Solution {
public:
    long long minimumPerimeter(long long neededApples) {

        long long h = 1e6;
        long long l = 0;

        long long ans = INT_MAX;

        while (l <= h) {
            long long mid = l + (h - l) / 2;
            
            long long apples = 2LL * mid * (mid + 1) *(2* mid +1);
            if (apples < neededApples) {
                l = mid + 1;
            }

            else if (apples >= neededApples) {
                ans = 8 * mid;
                h = mid - 1;
            }
        }

        return ans;
    }
};