class NumArray {
public:
    vector<int> nums;
    vector<int> sgt;
    int n;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        sgt.assign(4 * n, 0);
        build(0, n - 1, 0);
    }
    void build(int s, int e, int index) {
        // leaf node
        if (s == e) {
            sgt[index] = nums[s];
            return;
        }

        int m = (s + e) / 2;
        build(s, m, 2 * index + 1);
        build(m + 1, e, 2 * index + 2);

        sgt[index] = sgt[2 * index + 1] + sgt[2 * index + 2];
    }
    void update1(int s, int e, int index, int update_index, int update_value) {
        // leaf node
        if (s == e) {
            sgt[index] = update_value;
            return;
        }

        int m = (s + e) / 2;

        if (m >= update_index) {
            update1(s, m, 2 * index + 1, update_index, update_value);
        } else {
            update1(m + 1, e, 2 * index + 2, update_index, update_value);
        }

        sgt[index] = sgt[2 * index + 1] + sgt[2 * index + 2];
    }
    int query(int s, int e, int index, int l, int r) {
        // no overlap
        if (s > r || e < l) {
            return 0;
        }
        // complete overlap

        if (s >= l && e <= r) {
            return sgt[index];
        }
        // partial overlap

        int mid = (s + e) / 2;
        int left = query(s, mid, 2 * index + 1, l, r);
        int right = query(mid + 1, e, 2 * index + 2, l, r);

        return left + right;
    }
    void update(int index, int val) { update1(0, n - 1, 0, index, val); }

    int sumRange(int left, int right) {
        return query(0, n - 1, 0, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */