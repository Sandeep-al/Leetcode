class Solution {
public:
    int m;
    int n;
    vector<vector<int>>mat;
    int solve(int x, int y, int k) {
        int s_x = max(0, x - k);
        int s_y = max(0, y - k);
        int e_x = min(m - 1, x + k);
        int e_y = min(n - 1, y + k);
        int ans = 0;
        for (int i = s_x; i <= e_x; i++) {
            for (int j = s_y; j <= e_y; j++) {
                ans += mat[i][j];
            }
        }

        return ans;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        this->mat=mat;
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=solve(i,j,k);
            }
        }

        return ans;
    }
};