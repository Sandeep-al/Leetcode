class Solution {
public:
    // int solve(int n, int k) {

    //     if (n == 0) {
    //         return 0;
    //     }
    //     int len = (1 << n);
    //     if (k < len / 2) {
    //         return solve(n - 1, k);
    //     }

    //     return 1 - solve(n - 1, k - (len / 2));
    // }
    int kthGrammar(int n, int k) {
        // return solve(n-1,k-1);

        return __builtin_popcount(k - 1) % 2;
    }
};