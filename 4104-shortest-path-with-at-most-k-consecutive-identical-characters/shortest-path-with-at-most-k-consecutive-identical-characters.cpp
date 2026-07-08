class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq; // {weight,{node,k}}

        vector<vector<pair<int, int>>> adj(n);

        for (auto& it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));
        dist[0][1] = 0;

        pq.push({0, {0, 1}});

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();
            int curr_node = it.second.first;
            int curr_k = it.second.second;
            int curr_weight = it.first;
            if (curr_weight > dist[curr_node][curr_k])
                continue;
            if (curr_node == n - 1)
                return curr_weight;
        
            char curr_char = labels[curr_node];
            for (auto neighbour : adj[curr_node]) {
                int next_node = neighbour.first;
                int wt = neighbour.second;
                char curr_label = labels[next_node];
                int curr_ki = curr_k;
                if (curr_label == curr_char) {
                    curr_ki++;
                }
                else{
                    curr_ki=1;
                }

                if(curr_ki>k){
                    continue;
                }
                if (curr_weight + wt < dist[next_node][curr_ki]) {
                    dist[next_node][curr_ki] = curr_weight + wt;

                    pq.push({dist[next_node][curr_ki], {next_node, curr_ki}});
                }
            }
        }

        return -1;
    }
};