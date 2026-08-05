class SegmentTree {
private:
    
    vector<long long> tree0;
    vector<long long> tree1;
    int n;

    int leftChild(int node) { return 2 * node + 1; }
    int rightChild(int node) { return 2 * node + 2; }

    void update(int node, int start, int end, int idx, int parity, long long val) {
        if (start == end) {
            if (parity == 0) tree0[node] = max(tree0[node], val);
            else tree1[node] = max(tree1[node], val);
            return;
        }

        int mid = start + (end - start) / 2;

        if (idx <= mid) {
            update(leftChild(node), start, mid, idx, parity, val);
        } else {
            update(rightChild(node), mid + 1, end, idx, parity, val);
        }

       
        if (parity == 0) {
            tree0[node] = max(tree0[leftChild(node)], tree0[rightChild(node)]);
        } else {
            tree1[node] = max(tree1[leftChild(node)], tree1[rightChild(node)]);
        }
    }

    long long query(int node, int start, int end, int left, int right, int parity) {
        if (end < left || start > right) {
            return 0;
        }

        if (left <= start && end <= right) {
            return parity == 0 ? tree0[node] : tree1[node];
        }

        int mid = start + (end - start) / 2;
        return max(query(leftChild(node), start, mid, left, right, parity),
                   query(rightChild(node), mid + 1, end, left, right, parity));
    }

public:
    SegmentTree(int n) : n(n), tree0(4 * n, 0LL), tree1(4 * n, 0LL) {}

    void update(int idx, long long val, int parity) {
        if (n > 0) {
            update(0, 0, n - 1, idx, parity, val);
        }
    }

    long long query(int left, int right, int parity) {
        if (left > right || n == 0) {
            return 0;
        }
        return query(0, 0, n - 1, left, right, parity);
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        int n = nums.size();
        const int MAX_VAL = 100005;
        
      
        SegmentTree my_tree(MAX_VAL + 1); 

        
        vector<long long> dp0(n, 0); 
        vector<long long> dp1(n, 0);

        long long ans = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (i + k < n) {
                my_tree.update(nums[i + k], dp0[i + k], 0);
                my_tree.update(nums[i + k], dp1[i + k], 1);
            }

            
            long long best_next0 = my_tree.query(nums[i] + 1, MAX_VAL, 1);
            dp0[i] = nums[i] + best_next0;
            
            
            long long best_next1 = my_tree.query(0, nums[i] - 1, 0);
            dp1[i] = nums[i] + best_next1;

            ans = max({ans, dp0[i], dp1[i]});
        }

        return ans;
    }
};