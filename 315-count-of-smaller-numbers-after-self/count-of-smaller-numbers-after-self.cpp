class SegmentTree {
private:
    vector<int> tree;
    int n;

    int leftChild(int node) { return 2 * node + 1; }

    int rightChild(int node) { return 2 * node + 2; }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = 0;
            return;
        }

        int mid = start + (end - start) / 2;

        build(leftChild(node), start, mid);
        build(rightChild(node), mid + 1, end);

        tree[node] = tree[leftChild(node)] + tree[rightChild(node)];
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            
            tree[node] += val;
            return;
        }

        int mid = start + (end - start) / 2;

        if (idx <= mid)
            update(leftChild(node), start, mid, idx, val);
        else
            update(rightChild(node), mid + 1, end, idx, val);

        tree[node] = tree[leftChild(node)] + tree[rightChild(node)];
    }

    int query(int node, int start, int end, int left, int right) {
        if (end < left || start > right)
            return 0;

        if (left <= start && end <= right)
            return tree[node];

        int mid = start + (end - start) / 2;

        return query(leftChild(node), start, mid, left, right) +
               query(rightChild(node), mid + 1, end, left, right);
    }

public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0);

        if (n)
            build(0, 0, n - 1);
    }

    void update(int idx, int val) { update(0, 0, n - 1, idx, val); }

    int query(int left, int right) { return query(0, 0, n - 1, left, right); }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

       
        int OFFSET = 10000;
        int MAX_VAL = 20000;

        SegmentTree my_tree = SegmentTree(MAX_VAL + 1);
        vector<int> ans(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            int shifted_val = nums[i] + OFFSET;

            ans[i] = my_tree.query(0, shifted_val - 1);

            my_tree.update(shifted_val, 1);
        }

        return ans;
    }
};