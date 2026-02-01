class Solution {
public:
    int m;
    vector<vector<int>> arr;
    vector<long long>dp;
    long long solve(int i){
        
        if(i>=m) return 0;

        if(dp[i]!=-1) return dp[i];
        //take

        long long take =arr[i][0]+solve(i+arr[i][1]+1);

        long long nottake=solve(i+1);

        return dp[i]=max(take,nottake);


    }
    long long mostPoints(vector<vector<int>>& questions) {
        arr=questions;
        m=questions.size();
        dp.assign(m+1,-1);
        return solve(0);
    }
};