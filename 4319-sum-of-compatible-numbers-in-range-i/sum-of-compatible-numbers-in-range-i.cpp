class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum=0;

        for(int i=n-k ;i<=n+k;i++){

            if(i<0) continue;
            if((n & i)==0){
                sum+=i;
            }
        }

        return sum;
    }
};