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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {   
        int n=edges.size();
        DSU *my_dsu=new DSU(n);

        vector<int>ans={};
        for(auto &it:edges){
            int node1=it[0]-1;
            int node2=it[1]-1;

            if(my_dsu->find(node1)==my_dsu->find(node2)){
                ans=it;
            }
            else{
                my_dsu->unite(node1,node2);
            }

        }

        return ans;




    }
};