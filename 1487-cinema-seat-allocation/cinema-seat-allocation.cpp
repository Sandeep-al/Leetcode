class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mpp;
        for (auto& it : reservedSeats) {
            int curr_row = it[0];
            int curr_col = it[1];

            if (curr_col >= 2 && curr_col <= 5) {
                int x = mpp[curr_row];
                x = (1 << 0) | x;
                mpp[curr_row] = x;
            }
            if (curr_col >= 6 && curr_col <= 9) {
                int x = mpp[curr_row];
                x = (1 << 1) | x;
                mpp[curr_row] = x;
            }
            if (curr_col >= 4 && curr_col <= 5) {
                int x = mpp[curr_row];
                x = (1 << 2) | x;
                mpp[curr_row] = x;
            }
            if (curr_col >= 6 && curr_col <= 7) {
                int x = mpp[curr_row];
                x = (1 << 3) | x;
                mpp[curr_row] = x;
            }
        }

        int ans = 0;
        int blocked = 0;
        for (auto& it : mpp) {
            int x = it.second;
            blocked++;
            if (x == 0) {
                ans += 2;
            }
            if (x == 1 || x == 2 || x == 3 || x == 4 || x == 5 || x == 8 ||
                x == 10) {
                ans += 1;
            }
        }

        ans += (n - blocked) * 2;
        return ans;
    }
};