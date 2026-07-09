class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = find(parent[node]);
    }

    void unite(int u, int v) {

        u = find(u);
        v = find(v);

        if (u == v)
            return;

        if (size[u] < size[v])
            swap(u, v);

        parent[v] = u;
        size[u] += size[v];
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();
        DSU *dsu = new DSU(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    dsu->unite(i, j);
                }
            }
        }
        int to_remove=0;
        for(int i=0;i<n;i++){
            if(dsu->find(i)==i){
                to_remove++;
            }
        }

        return n-to_remove;
    }
};