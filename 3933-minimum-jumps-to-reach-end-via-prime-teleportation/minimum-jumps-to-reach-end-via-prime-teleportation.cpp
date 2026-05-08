class Solution {
public:

    vector<int> getPrimeFactors(int x) {

        vector<int> factors;

        for (int p = 2; p * p <= x; p++) {

            if (x % p == 0) {

                factors.push_back(p);

                while (x % p == 0) {

                    x /= p;
                }
            }
        }

        if (x > 1) {

            factors.push_back(x);
        }

        return factors;
    }

    bool isPrime(int n) {

        if (n < 2) return false;

        for (int i = 2; i * i <= n; i++) {

            if (n % i == 0)
                return false;
        }

        return true;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {

            vector<int> factors = getPrimeFactors(nums[i]);

            for (auto &f : factors) {

                mp[f].push_back(i);
            }
        }

        queue<int> q;

        vector<int> dist(n, 1e9);

        unordered_set<int> usedPrime;

        dist[0] = 0;

        q.push(0);

        while (!q.empty()) {

            int idx = q.front();

            q.pop();

            int steps = dist[idx];

            if (idx - 1 >= 0 && dist[idx - 1] > steps + 1) {

                dist[idx - 1] = steps + 1;

                q.push(idx - 1);
            }

            if (idx + 1 < n && dist[idx + 1] > steps + 1) {

                dist[idx + 1] = steps + 1;

                q.push(idx + 1);
            }

            if (isPrime(nums[idx]) && !usedPrime.count(nums[idx])) {

                usedPrime.insert(nums[idx]);

                for (auto &nextIdx : mp[nums[idx]]) {

                    if (dist[nextIdx] > steps + 1) {

                        dist[nextIdx] = steps + 1;

                        q.push(nextIdx);
                    }
                }
            }
        }

        return dist[n - 1];
    }
};