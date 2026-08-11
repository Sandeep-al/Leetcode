class SubgridSum {
private:
    vector<vector<long long>> prefix;

public:
    SubgridSum(const vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return;

        int m = grid.size();
        int n = grid[0].size();
        prefix.assign(m + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i + 1][j + 1] = grid[i][j] + prefix[i][j + 1] +
                                       prefix[i + 1][j] - prefix[i][j];
            }
        }
    }

    long long query(int r1, int c1, int r2, int c2) {
        return prefix[r2 + 1][c2 + 1] - prefix[r1][c2 + 1] -
               prefix[r2 + 1][c1] + prefix[r1][c1];
    }
};

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        SubgridSum my_sum(grid);
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(my_sum.query(0,0,i,j)<=k){
                    count++;
                }
            }
        }

        return count;
    }
};