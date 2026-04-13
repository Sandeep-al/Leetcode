class Solution {
public:
    vector<vector<int>> dungeon;
    int m;
    int n;
    
   
    vector<vector<int>> max_curr; 

    int solve(int i, int j, int curr) {
        if (i >= m || i < 0 || j < 0 || j >= n)
            return 0;
            
        curr += dungeon[i][j];
        if (curr <= 0)
            return 0;

        
        if (curr <= max_curr[i][j]) {
            return 0;
        }
        
        
        max_curr[i][j] = curr;

        if (i == m - 1 && j == n - 1)
            return 1;

        if (solve(i + 1, j, curr)) {
            return 1;
        }

        if (solve(i, j + 1, curr)) {
            return 1;
        }

        return 0;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        this->dungeon = dungeon;
        m = dungeon.size();
        n = dungeon[0].size();
        
        int can_max = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dungeon[i][j] < 0)
                    can_max += abs(dungeon[i][j]);
            }
        }

        int l = 1;
        int h = can_max;
        int ans = INT_MAX;
        
        while (l <= h) {
            int mid = l + (h - l) / 2;
            
            
            max_curr.assign(m, vector<int>(n, -1));

            if (solve(0, 0, mid)) {
                h = mid - 1;
                ans = min(ans, mid);
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};