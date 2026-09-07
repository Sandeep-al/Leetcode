class Solution {
public:
    int distinctSubseqII(string s) {
        vector<long long> last(26,0);

        long long total=0;
        
        int mod=1e9+7;
        for(char ch:s){
            int idx= ch-'a';
            long long oldtotal=total;
            long long newSub=( oldtotal+1-last[idx]+ mod) % mod;
            total=(total + newSub)% mod;
            last[idx]=(last[idx]+newSub)%mod;
            
        }

        return total;
    }
};