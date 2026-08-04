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

        tree[node] = max(tree[leftChild(node)], tree[rightChild(node)]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = max(tree[node], val);
            return;
        }

        int mid = start + (end - start) / 2;

        if (idx <= mid)
            update(leftChild(node), start, mid, idx, val);
        else
            update(rightChild(node), mid + 1, end, idx, val);

        tree[node] = max(tree[leftChild(node)], tree[rightChild(node)]);
    }

    int query(int node, int start, int end, int left, int right) {

        if (end < left || start > right)
            return 0;

        if (left <= start && end <= right)
            return tree[node];

        int mid = start + (end - start) / 2;

        return max(query(leftChild(node), start, mid, left, right),
                   query(rightChild(node), mid + 1, end, left, right));
    }

public:
    SegmentTree(int n) {
        this->n=n;
        tree.assign(4 * n, 0);

        if (n)
            build(0, 0, n - 1);
    }

    void update(int idx, int val) { update(0, 0, n - 1, idx, val); }

    int query(int left, int right) { return query(0, 0, n - 1, left, right); }
};
class Solution {
public:
    int k;
    vector<int> nums;
    SegmentTree* my_tree;
    int dp[100005];
    int solve(int idx) {

        int curr = nums[idx];
        int l = curr + 1;
        int r = min(100000, curr + k);
        int ans = 0;
        if (l <= r) {
            ans = my_tree->query(l, r);
        }
        my_tree->update(curr, ans + 1);
        return ans + 1;
    }
    int lengthOfLIS(vector<int>& nums, int k) {
        this->nums = nums;
        int n = nums.size();
        this->k = k;
        my_tree = new SegmentTree(100001);

        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans = max(ans, solve(i));
        }

        return ans;
    }
};
