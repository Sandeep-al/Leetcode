class Solution {
public:
    int waviness(int x) {

        string s = to_string(x);
        if(s.size()<3) return 0;
        int count = 0;
        for (int i = 1; i < s.size() - 1; i++) {
            int digit = s[i] - '0';

            int left = s[i - 1] - '0';
            int right = s[i + 1] - '0';

            if (digit > left && digit > right)
                count++;
            else if (digit < left && digit < right)
                count++;
        }
        return count;
    }
    int totalWaviness(int num1, int num2) {
        int total = 0;
        for (int i = num1; i <= num2; i++) {
            total += waviness(i);
        }

        return total;
    }
};