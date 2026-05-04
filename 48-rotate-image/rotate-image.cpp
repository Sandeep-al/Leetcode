class Solution {
public:
    void reverse(vector<int>& m) {
        int i = 0;
        int j = m.size() - 1;
        while (i < j) {
            swap(m[i], m[j]);
            i++;
            j--;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i]);
        }
    }
};