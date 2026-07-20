class Solution {
public:
    const long long INF = 4e18;

    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        vector<vector<long long>> dist(26, vector<long long>(26, INF));

        for (int i = 0; i < 26; i++)
            dist[i][i] = 0;

        for (int i = 0; i < cost.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';

            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {

                if (dist[i][k] == INF)
                    continue;

                for (int j = 0; j < 26; j++) {

                    if (dist[k][j] == INF)
                        continue;

                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
                }
            }
        }

        long long ans = 0;

        for (int i = 0; i < source.size(); i++) {

            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if (dist[u][v] == INF)
                return -1;

            ans += dist[u][v];
        }

        return ans;
    }
};