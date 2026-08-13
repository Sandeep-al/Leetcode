class Node {
public:
    int len;
    int best;
    char left;
    char right;
    int left_len;
    int right_len;
};

class SegmentTree {
private:
    vector<Node> tree;
    int n;
    string s;

    int leftChild(int node) { return 2 * node + 1; }

    int rightChild(int node) { return 2 * node + 2; }

    Node merge(Node L, Node R) {
        Node cur;

        cur.len = L.len + R.len;
        cur.left = L.left;
        cur.right = R.right;

        int cross = 0;

        if (L.right == R.left)
            cross = L.right_len + R.left_len;

        cur.left_len = L.left_len;

        if (L.left_len == L.len && L.right == R.left)
            cur.left_len = L.len + R.left_len;

        cur.right_len = R.right_len;

        if (R.right_len == R.len && L.right == R.left)
            cur.right_len = R.len + L.right_len;

        cur.best = max({L.best, R.best, cross});

        return cur;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node].len = 1;
            tree[node].best = 1;
            tree[node].left = s[start];
            tree[node].right = s[start];
            tree[node].left_len = 1;
            tree[node].right_len = 1;
            return;
        }

        int mid = (start + end) / 2;

        build(leftChild(node), start, mid);
        build(rightChild(node), mid + 1, end);

        tree[node] = merge(tree[leftChild(node)], tree[rightChild(node)]);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node].len = 1;
            tree[node].best = 1;
            tree[node].left = ch;
            tree[node].right = ch;
            tree[node].left_len = 1;
            tree[node].right_len = 1;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            update(leftChild(node), start, mid, idx, ch);
        else
            update(rightChild(node), mid + 1, end, idx, ch);

        tree[node] = merge(tree[leftChild(node)], tree[rightChild(node)]);
    }

    Node query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return {0, 0, '#', '#', 0, 0};

        if (l <= start && end <= r)
            return tree[node];

        int mid = (start + end) / 2;

        Node L = query(leftChild(node), start, mid, l, r);
        Node R = query(rightChild(node), mid + 1, end, l, r);

        if (L.len == 0)
            return R;

        if (R.len == 0)
            return L;

        return merge(L, R);
    }

public:
    SegmentTree(string str) {
        s = str;
        n = s.size();

        tree.resize(4 * n);

        if (n)
            build(0, 0, n - 1);
    }

    void update(int idx, char ch) {
        s[idx] = ch;
        update(0, 0, n - 1, idx, ch);
    }

    int query(int l, int r) { return query(0, 0, n - 1, l, r).best; }
};
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        int k = queryCharacters.size();
        SegmentTree my_tree(s);
        int n = s.size();
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            int idx = queryIndices[i];
            int ch = queryCharacters[i];

            my_tree.update(idx, ch);
            ans.push_back(my_tree.query(0, n - 1));
        }

        return ans;
    }
};