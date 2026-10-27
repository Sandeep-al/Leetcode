class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> yo(m, string(n, '#'));

        for(int i=0;i<m;i++){
            yo[i][n-1]='.';
        }
        for(int i=0;i<n;i++){
            yo[0][i]='.';
        }
        return yo;
    }
};