class Solution {
public:
    int findComplement(int num) {
        int x=num;
        long long yo=1;
        while(x!=0){
            x=x/2;
            yo=yo*2;
        }
        if(num==0) return 1;
        return (yo-1)-num;
    }
};