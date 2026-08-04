class SegmentTree {
private:
    vector<int> tree;
    int n;

    int leftChild(int node) { return 2 * node + 1; }

    int rightChild(int node) { return 2 * node + 2; }

    void build(int node, int start, int end, const vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;

        build(leftChild(node), start, mid, arr);
        build(rightChild(node), mid + 1, end, arr);

        tree[node] = tree[leftChild(node)] + tree[rightChild(node)];
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] +=1;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            update(leftChild(node), start, mid, idx, val);
        else
            update(rightChild(node), mid + 1, end, idx, val);

        tree[node] = tree[leftChild(node)] + tree[rightChild(node)];
    }

    int query(int node, int start, int end, int left, int right) {
        // No overlap
        if (end < left || start > right)
            return 0;

        // Complete overlap
        if (left <= start && end <= right)
            return tree[node];

        int mid = (start + end) / 2;

        return query(leftChild(node), start, mid, left, right) +
               query(rightChild(node), mid + 1, end, left, right);
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.assign(4 * n, 0);

        if (n)
            build(0, 0, n - 1, arr);
    }

    void update(int idx, int val) { update(0, 0, n - 1, idx, val); }

    int query(int left, int right) { return query(0, 0, n - 1, left, right); }
};
class Solution {
public:
    int MOD = 1e9 + 7;
    int createSortedArray(vector<int>& instructions) {
        vector<int> freq(1e5 + 1, 0);

        auto my_tree = SegmentTree(freq);

        int cost = 0;
        for (auto& it : instructions) {
            my_tree.update(it, 1);
            int element_lesser = my_tree.query(0, it - 1);
            int element_greater = my_tree.query(it + 1, 1e5);

            int mini = min(element_lesser, element_greater);
            cost = (cost + mini) % MOD;
        }

        return cost;
    }
};