class Solution {
public:
    vector<string> board;
    int n;
    const int mod=1e9+7;
    pair<int,int> dp[101][101];
    pair<int, int> solve(int idx1, int idx2) {

        if (idx1 < 0 || idx2 < 0)
            return {INT_MIN, INT_MIN};
        if (idx1 == 0 && idx2 == 0) {
            return {0, 1};
        }
        if (board[idx1][idx2] == 'X')
            return {INT_MIN, INT_MIN};

        auto d= dp[idx1][idx2];
        if(d.first!=-1 && d.second!=-1){
            return d;
        }
        int maxi = INT_MIN;
        int count = 0;
        int val =
            (idx1 == n - 1 && idx2 == n - 1) ? 0 : board[idx1][idx2] - '0';
        auto way1 = solve(idx1 - 1, idx2);
        if (way1.first != INT_MIN) {
            if (way1.first > maxi) {
                maxi = way1.first;
                count = way1.second;
            } else if (way1.first == maxi) {
                count =(count+ way1.second) % mod;
            }
        }
        auto way2 = solve(idx1 - 1, idx2 - 1);
        if (way2.first != INT_MIN) {
            if (way2.first > maxi) {
                maxi = way2.first;
                count = way2.second;
            } else if (way2.first == maxi) {
                count =(count+ way2.second) % mod;
            }
        }
        auto way3 = solve(idx1, idx2 - 1);
        if (way3.first != INT_MIN) {
            if (way3.first > maxi) {
                maxi = way3.first;
                count = way3.second;
            } else if (way3.first == maxi) {
                count =(count+ way3.second) % mod;
            }
        }

        if (maxi == INT_MIN) {
            return dp[idx1][idx2]={INT_MIN, INT_MIN};
        }

        return dp[idx1][idx2]={maxi + val, count};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {

        n = board.size();
        this->board = board;
        memset(dp,-1,sizeof(dp));
        auto it = solve(n - 1, n - 1);
        
        return {max(0,it.first), max(0,it.second)};
    }
};