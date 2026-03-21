class Solution {
public:
    int original;
    int m;
    int n;
    int colour;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void solve(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || j >= n || i >= m || grid[i][j] != original) {
            return;
        }

        grid[i][j] = colour;

        for (auto& it : directions) {
            int temp_i = i + it[0];
            int temp_j = j + it[1];

            solve(temp_i, temp_j, grid);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        original = image[sr][sc];
        m = image.size();
        n = image[0].size();
        colour = color;
        if (original == color) return image;
        solve(sr, sc, image);
        return image;
    }
};