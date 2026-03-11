class Solution {
public:
    int bitwiseComplement(int n) {
        int x=n;
        int yo=1;
        while(x!=0){
            x=x/2;
            yo=yo*2;
        }
        if(n==0) return 1;
        return (yo-1)-n;
    }
};