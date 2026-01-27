class Solution {
public:
    vector<vector<int>> travel{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m;
    int n;
    int starting_pixel_colour;
    void fill_colour(int i, int j, int color, vector<vector<int>>& image) {

        if (i < 0 || i >= m || j < 0 || j >= n ||
            image[i][j] != starting_pixel_colour) {
            return;
        }

        image[i][j] = color;

        for (auto& it : travel) {
            int temp_i = it[0] + i;
            int temp_j = it[1] + j;

            fill_colour(temp_i, temp_j, color, image);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        m = image.size();
        n = image[0].size();

        starting_pixel_colour = image[sr][sc];

        if (starting_pixel_colour == color)
            return image;

        fill_colour(sr, sc, color, image);
        return image;
    }
};