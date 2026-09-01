class Solution {
public:
    struct Node {
        int i;
        int j;
        int energy;
        int mask;
        int cost;

        Node(int i, int j, int energy, int mask, int cost)
            : i(i), j(j), energy(energy), mask(mask), cost(cost) {}
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int start_i, start_j;
        int litterCount = 0;

        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    start_i = i;
                    start_j = j;
                }
                if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        // 1. Changed to standard queue
        queue<Node> q;

        // 2. Replaced 'dist' with a 'visited' boolean array to prevent cycles
        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(
                   n, vector<vector<bool>>(
                          energy + 1, vector<bool>(1 << litterCount, false))));

        // starting state
        int startMask = 0;

        visited[start_i][start_j][energy][startMask] = true;
        q.push(Node(start_i, start_j, energy, startMask, 0));

        while (!q.empty()) {
            Node curr = q.front();
            q.pop();

            int curr_i = curr.i;
            int curr_j = curr.j;
            int curr_energy = curr.energy;
            int curr_mask = curr.mask;
            int curr_cost = curr.cost;

            // all litter collected
            if (curr_mask == (1 << litterCount) - 1) {
                return curr_cost;
            }

            // DOWN
            if (curr_i + 1 < m && classroom[curr_i + 1][curr_j] != 'X') {
                int ni = curr_i + 1;
                int nj = curr_j;
                int newmask = curr_mask;
                int newenergy = curr_energy;

                if (classroom[ni][nj] == 'L') {
                    int id = litterId[ni][nj];
                    newmask = curr_mask | (1 << id);
                }

                if (classroom[ni][nj] == 'R') {
                    newenergy = energy;
                } else {
                    newenergy = curr_energy - 1;
                }

                if (curr_energy > 0 && newenergy >= 0 &&
                    !visited[ni][nj][newenergy][newmask]) {
                    
                    visited[ni][nj][newenergy][newmask] = true;
                    q.push(Node(ni, nj, newenergy, newmask, curr_cost + 1));
                }
            }

            // UP
            if (curr_i - 1 >= 0 && classroom[curr_i - 1][curr_j] != 'X') {
                int ni = curr_i - 1;
                int nj = curr_j;
                int newmask = curr_mask;
                int newenergy = curr_energy;

                if (classroom[ni][nj] == 'L') {
                    int id = litterId[ni][nj];
                    newmask = curr_mask | (1 << id);
                }

                if (classroom[ni][nj] == 'R') {
                    newenergy = energy;
                } else {
                    newenergy = curr_energy - 1;
                }

                if (curr_energy > 0 && newenergy >= 0 &&
                    !visited[ni][nj][newenergy][newmask]) {
                    
                    visited[ni][nj][newenergy][newmask] = true;
                    q.push(Node(ni, nj, newenergy, newmask, curr_cost + 1));
                }
            }

            // RIGHT
            if (curr_j + 1 < n && classroom[curr_i][curr_j + 1] != 'X') {
                int ni = curr_i;
                int nj = curr_j + 1;
                int newmask = curr_mask;
                int newenergy = curr_energy;

                if (classroom[ni][nj] == 'L') {
                    int id = litterId[ni][nj];
                    newmask = curr_mask | (1 << id);
                }

                if (classroom[ni][nj] == 'R') {
                    newenergy = energy;
                } else {
                    newenergy = curr_energy - 1;
                }

                if (curr_energy > 0 && newenergy >= 0 &&
                    !visited[ni][nj][newenergy][newmask]) {
                    
                    visited[ni][nj][newenergy][newmask] = true;
                    q.push(Node(ni, nj, newenergy, newmask, curr_cost + 1));
                }
            }

            // LEFT
            if (curr_j - 1 >= 0 && classroom[curr_i][curr_j - 1] != 'X') {
                int ni = curr_i;
                int nj = curr_j - 1;
                int newmask = curr_mask;
                int newenergy = curr_energy;

                if (classroom[ni][nj] == 'L') {
                    int id = litterId[ni][nj];
                    newmask = curr_mask | (1 << id);
                }

                if (classroom[ni][nj] == 'R') {
                    newenergy = energy;
                } else {
                    newenergy = curr_energy - 1;
                }

                if (curr_energy > 0 && newenergy >= 0 &&
                    !visited[ni][nj][newenergy][newmask]) {
                    
                    visited[ni][nj][newenergy][newmask] = true;
                    q.push(Node(ni, nj, newenergy, newmask, curr_cost + 1));
                }
            }
        }

        return -1;
    }
};