class Solution {
public:
    int m;
    int n;
    string s1;
    string s2;
    int dp[1001][1001];
    int solve(int idx1, int idx2) {
        
        if (idx1 == m && idx2 == n)
            return 0;
        if (idx1 >= m ){
            int sum=0;
            while(idx2<n){
                sum+=int(s2[idx2]);
                idx2++;
            }

            return sum;
        }
        if(idx2>=n){
            int sum=0;
            while(idx1<m){
                sum+=int(s1[idx1]);
                idx1++;
            }

            return sum;
        }

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
            
        int mini = INT_MAX;
        if (s1[idx1] == s2[idx2]) {
            int solve_next = solve(idx1 + 1, idx2 + 1);
            if (solve_next != INT_MAX) {
                mini = min(mini, solve_next);
            }
        }

        int next_solve1 = solve(idx1 + 1, idx2);
        int next_solve2 = solve(idx1, idx2 + 1);

        if (next_solve1 != INT_MAX) {
            mini = min(mini, next_solve1 + int(s1[idx1]));
        }
        if (next_solve2 != INT_MAX) {
            mini = min(mini, next_solve2 + int(s2[idx2]));
        }

        return dp[idx1][idx2]=mini;
    }
    int minimumDeleteSum(string s1, string s2) {
        this->s1=s1;
        this->s2=s2;
        m = s1.size();
        n = s2.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0);
    }
};