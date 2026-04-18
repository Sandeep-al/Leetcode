class Solution {
public:
    int countDivisors(int n) {
    int cnt = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i == n / i)
                cnt += 1;   
            else
                cnt += 2;   
        }
    }

    return cnt;
}
    bool isThree(int n) {
        
        return countDivisors(n)==3;
    }
};