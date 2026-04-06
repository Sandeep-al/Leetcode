class Solution {
public:
    // 1 for north
    // 2 for east
    // 3 for south
    // 4 for west
    int n;
    int maxi;
    vector<int> commands;
    vector<vector<int>> obstacles;
    unordered_set<long long> st;
    long long encode(int x, int y) {
        return ((long long)x << 32) | (unsigned int)y;
    }
    int found(int i, int j) { return st.count(encode(i, j)); }
    void solve(int i, int j, int direction, int idx) {

        maxi = max(maxi, i * i + j * j);
        if (idx == n)
            return;

        
        int to_do = commands[idx];
        int new_direction = direction;
        if (to_do >= 1) {
            if (direction == 1) {
                // increase j
                for (int x = 1; x <= to_do; x++) {
                    int dj = x + j;
                    if (found(i, dj)) {
                        solve(i, dj - 1, direction, idx + 1);
                        return;
                    }
                }

                solve(i, j + to_do, direction, idx + 1);
                return;
            } else if (direction == 2) {
                // increase i

                for (int x = 1; x <= to_do; x++) {
                    int di = x + i;
                    if (found(di, j)) {
                        solve(di - 1, j, direction, idx + 1);
                        return;
                    }
                }

                solve(i + to_do, j, direction, idx + 1);
                return;
            } else if (direction == 3) {
                // decrease j
                for (int x = 1; x <= to_do; x++) {
                    int dj = j - x;
                    if (found(i, dj)) {
                        solve(i, dj + 1, direction, idx + 1);
                        return;
                    }
                }

                solve(i, j - to_do, direction, idx + 1);
                return;

            } else {

                for (int x = 1; x <= to_do; x++) {
                    int di = i - x;
                    if (found(di, j)) {
                        solve(di + 1, j, direction, idx + 1);
                        return;
                    }
                }

                solve(i - to_do, j, direction, idx + 1);
                // decrease i
                return;
            }
        }
        
        else if (to_do == -1) {

            if (direction == 1) {
                new_direction = 2;
            } else if (direction == 2) {
                new_direction = 3;
            } else if (direction == 3) {
                new_direction = 4;
            } else {
                new_direction = 1;
            }
        }

        else {
            if (direction == 1) {
                new_direction = 4;
            } else if (direction == 2) {
                new_direction = 1;
            } else if (direction == 3) {
                new_direction = 2;
            } else {
                new_direction = 3;
            }
        }

        solve(i, j, new_direction, idx + 1);
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        n = commands.size();
        this->commands = commands;
        this->obstacles = obstacles;
        for (auto& v : obstacles) {
            st.insert(encode(v[0], v[1]));
        }
        maxi=INT_MIN;

        solve(0, 0, 1,0);
        return maxi;
    }
};