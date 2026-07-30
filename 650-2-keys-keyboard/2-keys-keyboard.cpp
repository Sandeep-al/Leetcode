class Solution {
public:
    int minSteps(int n) {
        if (n == 1)
            return 0;
        int x = n;
        int mini = 0;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int cost = 0;

                while (n % i == 0) {
                    n /= i;

                    cost += i;
                }
                mini += cost;
            }
        }
        
        if (n > 1) {
            mini += n;
        }

        return mini;
    }
};
