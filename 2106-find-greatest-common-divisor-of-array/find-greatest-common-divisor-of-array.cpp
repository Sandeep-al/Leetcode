class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int findGCD(vector<int>& nums) {
        int largest = INT_MIN;
        int smallest = INT_MAX;

        for (auto& it : nums) {
            largest = max(largest, it);
            smallest = min(smallest, it);
        }

        return gcd(smallest, largest);
    }
};