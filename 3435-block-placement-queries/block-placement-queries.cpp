class SegmentTree {
public:
    int n;
    vector<int> seg;

    SegmentTree(int sz) {
        n = sz;
        seg.assign(4 * n + 5, 0);
    }

    void update(int idx, int val, int node, int l, int r) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(idx, val, 2 * node + 1, l, mid);
        else
            update(idx, val, 2 * node + 2, mid + 1, r);

        seg[node] = max(seg[2 * node + 1], seg[2 * node + 2]);
    }

    int query(int ql, int qr, int node, int l, int r) {
        if (r < ql || l > qr)
            return 0;

        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) >> 1;

        return max(
            query(ql, qr, 2 * node + 1, l, mid),
            query(ql, qr, 2 * node + 2, mid + 1, r)
        );
    }

    void update(int idx, int val) {
        update(idx, val, 0, 0, n - 1);
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(l, r, 0, 0, n - 1);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        int MX = 0;

        for (auto &q : queries)
            MX = max(MX, q[1]);

        MX += 5;

        SegmentTree st(MX + 1);

        set<int> obs;
        obs.insert(0);
        obs.insert(MX);

        st.update(MX, MX);

        vector<bool> ans;

        for (auto &q : queries) {

            if (q[0] == 1) {

                int x = q[1];

                auto itR = obs.upper_bound(x);
                auto itL = prev(itR);

                int R = *itR;
                int L = *itL;

                obs.insert(x);

                st.update(x, x - L);
                st.update(R, R - x);
            }
            else {

                int x = q[1];
                int sz = q[2];

                auto it = prev(obs.upper_bound(x));

                int lastObstacle = *it;

                int bestGap = st.query(0, lastObstacle);

                bool ok = false;

                if (bestGap >= sz)
                    ok = true;

                if (x - lastObstacle >= sz)
                    ok = true;

                ans.push_back(ok);
            }
        }

        return ans;
    }
};