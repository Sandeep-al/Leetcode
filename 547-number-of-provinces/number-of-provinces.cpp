class Solution {
public:
    int n;
    vector<vector<int>> isConnected;
    vector<int>vis;
    void solve(int node) {
        vis[node] = 1;

        for (int i = 0; i < n; i++) {
            if (isConnected[node][i] == 1 && vis[i] == 0) {
                solve(i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        this->isConnected = isConnected;
        int x = 0;
        vis.assign(n,0);
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                solve(i);
                x++;
            }
        }

        return x;
    }
};