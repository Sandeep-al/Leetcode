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
        int start_i = 0, start_j = 0;
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

        queue<Node> q;

        vector<vector<vector<int>>> max_energy(
            m, vector<vector<int>>(
                   n, vector<int>(1 << litterCount, -1)));

        int startMask = 0;

        max_energy[start_i][start_j][startMask] = energy;
        q.push(Node(start_i, start_j, energy, startMask, 0));

        while (!q.empty()) {
            Node curr = q.front();
            q.pop();

            int curr_i = curr.i;
            int curr_j = curr.j;
            int curr_energy = curr.energy;
            int curr_mask = curr.mask;
            int curr_cost = curr.cost;

            if (curr_mask == (1 << litterCount) - 1) {
                return curr_cost;
            }

            if (curr_i + 1 < m && classroom[curr_i + 1][curr_j] != 'X') {
                int ni = curr_i + 1;
                int nj = curr_j;
                int newmask = curr_mask;
                int newenergy = curr_energy;

                if (classroom[ni][nj] == 'L') {
                    newmask = curr_mask | (1 << litterId[ni][nj]);
                }

                if (classroom[ni][nj] == 'R') {
                    newenergy = energy;
                } else {
                    newenergy = curr_energy - 1;
                }

                if (curr_energy > 0 && newenergy >= 0 &&
                    newenergy > max_energy[ni][nj][newmask]) {
                    
                    max_energy[ni][nj][newmask] = newenergy;
                    q.push(Node(ni, nj, newenergy, newmask, curr_cost + 1));
                }
            }

            if (curr_i - 1 >= 0 && classroom[curr_i - 1][curr_j] != 'X') {
                int ni = curr_i - 1;
                int nj = curr_j;
                int newmask = curr_mask;
                int newenergy = curr_energy;

                if (classroom[ni][nj] == 'L') {
                    newmask = curr_mask | (1 << litterId[ni][nj]);
                }

                if (classroom[ni][nj] == 'R') {
                    newenergy = energy;
                } else {
                    newenergy = curr_energy - 1;
                }

                if (curr_energy > 0 && newenergy >= 0 &&
                    newenergy > max_energy[ni][nj][newmask]) {
                    
                    max_energy[ni][nj][newmask] = newenergy;
                    q.push(Node(ni, nj, newenergy, newmask, curr_cost + 1));
                }
            }

            if (curr_j + 1 < n && classroom[curr_i][curr_j + 1] != 'X') {
                int ni = curr_i;
                int nj = curr_j + 1;
                int newmask = curr_mask;
                int newenergy = curr_energy;

                if (classroom[ni][nj] == 'L') {
                    newmask = curr_mask | (1 << litterId[ni][nj]);
                }

                if (classroom[ni][nj] == 'R') {
                    newenergy = energy;
                } else {
                    newenergy = curr_energy - 1;
                }

                if (curr_energy > 0 && newenergy >= 0 &&
                    newenergy > max_energy[ni][nj][newmask]) {
                    
                    max_energy[ni][nj][newmask] = newenergy;
                    q.push(Node(ni, nj, newenergy, newmask, curr_cost + 1));
                }
            }

            if (curr_j - 1 >= 0 && classroom[curr_i][curr_j - 1] != 'X') {
                int ni = curr_i;
                int nj = curr_j - 1;
                int newmask = curr_mask;
                int newenergy = curr_energy;

                if (classroom[ni][nj] == 'L') {
                    newmask = curr_mask | (1 << litterId[ni][nj]);
                }

                if (classroom[ni][nj] == 'R') {
                    newenergy = energy;
                } else {
                    newenergy = curr_energy - 1;
                }

                if (curr_energy > 0 && newenergy >= 0 &&
                    newenergy > max_energy[ni][nj][newmask]) {
                    
                    max_energy[ni][nj][newmask] = newenergy;
                    q.push(Node(ni, nj, newenergy, newmask, curr_cost + 1));
                }
            }
        }

        return -1;
    }
};