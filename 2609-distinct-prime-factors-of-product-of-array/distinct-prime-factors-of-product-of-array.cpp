class Solution {
public:
    unordered_set<int> mpp;
    void generate_primes(int n) {

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                while (n % i == 0) {
                    n /= i;
                    mpp.insert(i);
                }
            }
        }
        if (n > 1) {
            mpp.insert(n);
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        for (auto& it : nums) {
            generate_primes(it);
        }

        return mpp.size();
    }
};