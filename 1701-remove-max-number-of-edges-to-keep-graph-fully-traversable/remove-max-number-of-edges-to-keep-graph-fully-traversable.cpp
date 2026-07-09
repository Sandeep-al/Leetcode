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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU* alice = new DSU(n);
        DSU* bob = new DSU(n);

        int can_remove = 0;

        // Pass 1 : Type 3
        for (auto& it : edges) {
            int type = it[0];
            int node1 = it[1] - 1;
            int node2 = it[2] - 1;

            if (type != 3)
                continue;

            bool a1 = (alice->find(node1) == alice->find(node2));
            bool a2 = (bob->find(node1) == bob->find(node2));

            if (a1 && a2) {
                can_remove++;
            } else {
                alice->unite(node1, node2);
                bob->unite(node1, node2);
            }
        }

        // Pass 2 : Type 1
        for (auto& it : edges) {
            int type = it[0];
            int node1 = it[1] - 1;
            int node2 = it[2] - 1;

            if (type != 1)
                continue;

            if (alice->find(node1) == alice->find(node2)) {
                can_remove++;
            } else {
                alice->unite(node1, node2);
            }
        }

        // Pass 3 : Type 2
        for (auto& it : edges) {
            int type = it[0];
            int node1 = it[1] - 1;
            int node2 = it[2] - 1;

            if (type != 2)
                continue;

            if (bob->find(node1) == bob->find(node2)) {
                can_remove++;
            } else {
                bob->unite(node1, node2);
            }
        }

        // Connected Components Check
        int alice_count = 0;
        int bob_count = 0;

        for (int i = 0; i < n; i++) {
            if (alice->find(i) == i)
                alice_count++;

            if (bob->find(i) == i)
                bob_count++;
        }

        if (alice_count > 1 || bob_count > 1)
            return -1;

        return can_remove;
    }
};