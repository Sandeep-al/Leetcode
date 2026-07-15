class Solution {
public:
    int gcdOfOddEvenSums(int n) {

        int y=n*n+n;
        int x=n*n;

        return gcd(x,y);
    }
};