class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<long long >rowsum(m,0);
        vector<long long >colsum(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                colsum[i]+=grid[j][i];
            }
        }

        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rowsum[i]+=grid[i][j];
            }
        }

        vector<long long >prefix_sum_row(m,0);
        vector<long long >prefix_sum_col(n,0);
        long long  sum1=0;
        for(int i=0;i<m;i++){
            sum1+=rowsum[i];
            prefix_sum_row[i]=sum1;
        }
        long long  sum2=0;
        for(int i=0;i<n;i++){
            sum2+=colsum[i];
            prefix_sum_col[i]=sum2;
        }
        if(sum1%2==0){
        for(int i=0;i<m;i++){
            if(prefix_sum_row[i]==sum1/2){
                return true;
            }
        }
        }
        if(sum2%2==0){
        for(int i=0;i<n;i++){
            if(prefix_sum_col[i]==sum2/2){
                return true;
            }
        }}

        return false;
    }
};