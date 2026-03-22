class Solution {
public:
    vector<int> color;
    vector<vector<int>> graph;
    bool can_colour(int node, int c) {
        color[node] = c;

        for (auto& jt : graph[node]) {

            if (color[jt] == -1) {
                if (can_colour(jt, 1 - c) == false) {
                    return false;
                }
            } else if (color[jt] == c) {
                return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        this->graph=graph;
        int V = graph.size();

        color.assign(V, -1);

        for(int i=0;i<V;i++){
            if(color[i]==-1 && can_colour(i,0)==false){
                return false;
            }
        }
        return true;

        
    }
};