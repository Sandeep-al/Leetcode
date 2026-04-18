class Solution {
public:
    int reverse_it(int x){
        int z=0;
        while(x>0){
            int a=x%10;
            z=z*10+a;
            x=x/10;
        }

        return z;
    }
    int mirrorDistance(int n) {
        return abs(n-reverse_it(n));
    }
};