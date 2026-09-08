#include <numeric>
#include <string>
#include <vector>

class Solution {
public:
    int distinctSubseqII(std::string s) {
        long long endsWith[26] = {0};
        long long MOD = 1e9 + 7;

        for (char c : s) {
            long long currentTotal = 0;

            for (int i = 0; i < 26; i++) {
                currentTotal = (currentTotal + endsWith[i]) % MOD;
            }

            endsWith[c - 'a'] = (1 + currentTotal) % MOD;
        }

        long long totalDistinct = 0;
        for (int i = 0; i < 26; i++) {
            totalDistinct = (totalDistinct + endsWith[i]) % MOD;
        }

        return totalDistinct;
    }
};