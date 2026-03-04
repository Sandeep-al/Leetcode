class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rowsum(m, 0);
        vector<int> colsum(n, 0);

        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += mat[i][j];
            }
            rowsum[i] = sum;
        }

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += mat[j][i];
            }
            colsum[i] = sum;
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rowsum[i]==1 && colsum[j]==1 && mat[i][j]==1){
                    count++;
                }
            }
        }

        return count;
    }
};