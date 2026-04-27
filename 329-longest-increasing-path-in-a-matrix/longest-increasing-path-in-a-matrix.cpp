class Solution {
public:
    int m;
    int n;
    vector<vector<int>> grid;
    vector<vector<int>> dp;
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int solve(int i, int j) {

        if(dp[i][j]!=-1) return dp[i][j];
        int curr = grid[i][j];
        
        int ans = 1;

        // check forward paths
       
        for (auto& it : dir) {

            int idx = it[0] + i;
            int idy = it[1] + j;

            if (idx < 0 || idy < 0 || idx >= m || idy >= n ||
                 grid[idx][idy] <= curr) {
                continue;
            }

            
            ans = max(ans, 1 + solve(idx, idy));
        }
        
        

        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        grid = matrix;
        m = matrix.size();
        n = matrix[0].size();
        dp.assign(m,vector<int>(n,-1));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,solve(i,j));
            }
        }

        return ans;
    }
};