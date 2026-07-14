int dp[202][202][202];
class Solution {
public:
    vector<int>nums;
    int n;
    const int mod=1e9+7;
    
    int solve(int idx,int curr_gcd1,int curr_gcd2){
        if(idx==n){
            return (curr_gcd1==curr_gcd2 && curr_gcd1!=0);
        }

        if(dp[idx][curr_gcd1][curr_gcd2]!=-1){
            return dp[idx][curr_gcd1][curr_gcd2];
        }
        int new_curr_gcd1=gcd(curr_gcd1,nums[idx]);
        int new_curr_gcd2=gcd(curr_gcd2,nums[idx]);

        int ans=0;

        //pick it up for 1
        ans=(ans+solve(idx+1,new_curr_gcd1,curr_gcd2))%mod;
        ans=(ans+solve(idx+1,curr_gcd1,new_curr_gcd2))%mod;
        ans=(ans+solve(idx+1,curr_gcd1,curr_gcd2))%mod;

        return dp[idx][curr_gcd1][curr_gcd2]=ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        this->nums=nums;
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0);
    }
};