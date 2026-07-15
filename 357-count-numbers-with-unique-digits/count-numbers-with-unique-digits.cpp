class Solution {
public:
    
    int solve(int idx,int bitmask,int n){
        if(idx==n) return 1;

        int ans=0;

        for(int i=0;i<10;i++){
            if(idx==0 && i==0) continue;

            if(!(bitmask & (1<<i))){
                ans+=solve(idx+1,(bitmask | (1<<i)),n);
            }
        }

        return ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        
        if(n==0) return 1;
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=solve(0,0,i);
        }
        return ans+1;
    }
};