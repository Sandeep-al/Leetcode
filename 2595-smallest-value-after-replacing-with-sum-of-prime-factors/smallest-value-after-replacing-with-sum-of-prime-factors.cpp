class Solution {
public:
    vector<int> spf;
    int prime_factors_sum(int x) {
        int factors = 0;

        while (x > 1) {
            factors += spf[x];
            x /= spf[x];
        }

        return factors;
    }
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
    int smallestValue(int n) {
        buildSPF(n);
        while (spf[n] != n) {
            int x = prime_factors_sum(n);
            if(x==n){
                return x;
            }

            n=x;
        }

        return n;
    }
};