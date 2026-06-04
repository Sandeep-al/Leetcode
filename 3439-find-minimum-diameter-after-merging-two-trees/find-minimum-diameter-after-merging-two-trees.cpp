class Solution {
public:
    int max_diameter = 0;

    int calculateHeight(int node, int parent, const vector<vector<int>>& adj) {
        int max1 = 0;
        int max2 = 0;

        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                int child_height = calculateHeight(neighbor, node, adj);

                if (child_height > max1) {
                    max2 = max1;
                    max1 = child_height;
                } else if (child_height > max2) {
                    max2 = child_height;
                }
            }
        }

        max_diameter = max(max_diameter, max1 + max2);
        return max(max1, max2) + 1;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {

        
        int n = edges1.size() + 1;
        vector<vector<int>> adj1(n);
        for (const auto& edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        max_diameter = 0;
        calculateHeight(0, -1, adj1);
        int x1 = max_diameter;

        n = edges2.size() + 1;
        vector<vector<int>> adj2(n);
        for (const auto& edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }
        max_diameter = 0;
        calculateHeight(0, -1, adj2);
        int x2 = max_diameter;

        int path_through_centers = ((x1 + 1) / 2) + ((x2 + 1) / 2) + 1;

        return max({x1, x2, path_through_centers});
    }
};