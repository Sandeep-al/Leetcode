class Solution {
public:
    int countCommas(int n) {
        int length=0;
        int x=n;
        while(x>0){
            length++;
            x=x/10;
        }

        return (length-1)/3 * max(0,(n-999));
        
    }
};