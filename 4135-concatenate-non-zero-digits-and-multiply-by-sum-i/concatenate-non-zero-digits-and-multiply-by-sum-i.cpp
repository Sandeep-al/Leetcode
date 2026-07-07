class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long number=0;
        int multiplier=1;
        while(n>0){
            int curr=n%10;
            if(curr!=0){
                number=(curr*multiplier)+(number);
                multiplier*=10;
                
            }
            n=n/10;
            
            sum+=curr;
        }

        return number*sum;
    }
};