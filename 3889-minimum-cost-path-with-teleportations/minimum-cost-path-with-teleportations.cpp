#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

class Solution {
public:
    int n, m;

    // 1. Structure to store cell info for sorting
    struct Cell {
        int val, r, c;
    };
    
    // Global data structures
    vector<Cell> sorted_cells;
    int rank[81][81]; // To store rank of each cell (O(1) lookup)
    
    // 2. DP Arrays (Memoization)
    // dp_grid[i][j][k]: Min cost from (i, j) with k teleports remaining
    int dp_grid[81][81][12]; 
    
    // dp_tele[idx][k]: Min cost among all cells from sorted_cells[0...idx]
    int dp_tele[6405][12]; // 80*80 = 6400 max cells

    // Comparator for sorting
    static bool compareCells(const Cell& a, const Cell& b) {
        return a.val < b.val;
    }

    // --- FUNCTION 1: Sorted List Recursion (Replaces the Loop) ---
    // Returns the minimum 'solve' result among cells from index 0 to idx
    int getMinTeleport(int idx, int k) {
        // Base Case: No cells left to check
        if (idx < 0) return 1e9;

        // Memoization
        if (dp_tele[idx][k] != -1) return dp_tele[idx][k];

        // Option A: Current cell ka cost nikal lo
        // (Ye grid wale function ko call karega)
        int r = sorted_cells[idx].r;
        int c = sorted_cells[idx].c;
        int current_val = solve(r, c, k);

        // Option B: Piche wale cells ka best cost pucho (Recursion)
        int prev_best = getMinTeleport(idx - 1, k);

        // Store and return minimum of both
        return dp_tele[idx][k] = min(current_val, prev_best);
    }

    // --- FUNCTION 2: Grid Traversal (Main Logic) ---
    int solve(int i, int j, int k) {
        // Base Case: Reached Target
        if (i == n - 1 && j == m - 1) return 0;

        // Memoization
        if (dp_grid[i][j][k] != -1) return dp_grid[i][j][k];

        int res = 1e9;

        // 1. Move Down (Adding edge weight logic)
        // Note: Assuming standard grid path problem where moving to a cell adds its cost
        if (i + 1 < n) {
            int val = solve(i + 1, j, k);
            if (val != 1e9) res = min(res, val + global_grid[i + 1][j]);
        }

        // 2. Move Right
        if (j + 1 < m) {
            int val = solve(i, j + 1, k);
            if (val != 1e9) res = min(res, val + global_grid[i][j + 1]);
        }

        // 3. Teleport (Using Recursion, NO LOOP)
        if (k > 0) {
            // Step A: Find my rank (Lookup)
            int my_rank = rank[i][j];
            
            // Step B: Ask optimized function: "Best cost till my rank?"
            // We pass k-1 because teleport uses 1 move
            int tele_cost = getMinTeleport(my_rank, k - 1);
            
            if (tele_cost != 1e9) res = min(res, tele_cost);
        }

        return dp_grid[i][j][k] = res;
    }

    // Helper to store grid reference
    vector<vector<int>> global_grid;

    int minCost(vector<vector<int>>& grid, int k) {
        global_grid = grid;
        n = grid.size();
        m = grid[0].size();

        // 1. Reset Data & Memoization
        sorted_cells.clear();
        memset(dp_grid, -1, sizeof(dp_grid));
        memset(dp_tele, -1, sizeof(dp_tele));
        // Note: rank array reset ki zarurat nahi, overwrite ho jayega

        // 2. Flatten the Grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sorted_cells.push_back({grid[i][j], i, j});
            }
        }

        // 3. Sort Cells by Value
        sort(sorted_cells.begin(), sorted_cells.end(), compareCells);

        // 4. Assign Ranks (Grouping Logic - The Fix for Duplicate Values)
        // Jinki value same hai, un sabko same (rightmost) rank milegi
        for (int i = 0; i < sorted_cells.size(); ) {
            int j = i;
            // Find end of the current value group
            while (j < sorted_cells.size() && sorted_cells[j].val == sorted_cells[i].val) {
                j++;
            }
            // 'j' ab next new value pe hai. Group range is [i, j-1]
            // Sabko 'j-1' rank assign karo
            for (int x = i; x < j; x++) {
                int r = sorted_cells[x].r;
                int c = sorted_cells[x].c;
                rank[r][c] = j - 1; // Rightmost index assigned
            }
            // Jump i to j
            i = j;
        }

        // 5. Start Recursion
        return solve(0, 0, k);
    }
};