class Solution {
public:
    vector<int> spf;

    void buildSPF(int N) {
        spf.assign(N + 1, 0);

        for (int i = 2; i <= N; i++) {

            if (spf[i] != 0)
                continue;

            spf[i] = i;

            for (long long j = 1LL * i * i; j <= N; j += i) {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }

    int countPrimes(int n) {
        buildSPF(n);
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (spf[i] == i) {
                count++;
            }
        }
        return count;
    }
};