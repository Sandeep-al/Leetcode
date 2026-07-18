class Solution {
public:
    vector<pair<int, int>> depth;
    void compute(int dp, TreeNode* root, int parent) {
        if (root == nullptr)
            return;

        depth[root->val] = {dp, parent};

        compute(dp + 1, root->left, root->val);
        compute(dp + 1, root->right, root->val);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        depth.assign(101, {});
        compute(0, root, -1);
        auto [dp1, p1] = depth[x];
        auto [dp2, p2] = depth[y];

        return dp1 == dp2 && p1 != p2;
    }
};