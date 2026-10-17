class Solution {
public:
    vector<long long> extra;
    vector<long long> diff;
    int r;
    int k;
    int n;
    bool check(long long x) {
        extra.assign(n + 1, 0);
        int yo = k;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                extra[i] += extra[i - 1];
            }

            if ((diff[i] + extra[i]) < x) {
                long long cover = x - (diff[i] + extra[i]);
                if (yo < cover) {
                    return 0;
                }

                extra[i] += cover;
                extra[min(n - 1, i + 2 * r) + 1] -= cover;
                yo -= cover;
            }
        }

        return 1;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        this->r = r;
        this->k = k;
        n = stations.size();

        diff.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int l = max(0, i - r);
            int x = min(n - 1, i + r);

            diff[l] += stations[i];
            diff[x + 1] -= stations[i];
        }

        for (int i = 1; i <= n; i++) {
            diff[i] += diff[i - 1];
        }

        long long lo = 0;
        long long hi = LLONG_MAX;

        while (hi - lo > 1) {
            long long mid = (hi - lo) / 2 + lo;

            if (check(mid)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        return lo;
    }
};