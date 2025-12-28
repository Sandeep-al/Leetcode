class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int cnt=0;
        for(auto &it:grid){
            for(auto jt:it){
                if(jt<0){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};