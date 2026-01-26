class Solution {
public:
    int m;
    int dp[31][31][31];

   
    bool solve(string& s1, string& s2, int len, int i, int j) {
        
        if (len == 1) {
            return s1[i] == s2[j];
        }
        
        if (dp[len][i][j] != -1) {
            return dp[len][i][j];
        }

        for (int k = 1; k < len; k++) {
            
           
         
            if (solve(s1, s2, k, i, j) && solve(s1, s2, len - k, i + k, j + k)) {
                return dp[len][i][j] = true;
            }

            
            if (solve(s1, s2, k, i, j + len - k) && solve(s1, s2, len - k, i + k, j)) {
                return dp[len][i][j] = true;
            }
        }
        return dp[len][i][j] = false;
    }

    bool isScramble(string s1, string s2) {
        m = s1.size();
        memset(dp, -1, sizeof(dp));
        
        return solve(s1, s2, m, 0, 0); 
    }
};