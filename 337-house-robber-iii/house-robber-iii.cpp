/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> dfs(TreeNode* root) {

        if (root == nullptr)
            return {0, 0};

        int l_take = 0;
        int l_not_take = 0;

        int r_take = 0;
        int r_not_take = 0;

        if (root->left) {
            auto left = dfs(root->left);
            l_take = left.first;
            l_not_take = left.second;
        }
        if (root->right) {

            auto right = dfs(root->right);
            r_take = right.first;
            r_not_take = right.second;
        }

        int curr_take = 0;
        int curr_not_take = 0;

        curr_take = root->val + l_not_take + r_not_take;
        curr_not_take = max(l_take, l_not_take) + max(r_take, r_not_take);

        return {curr_take, curr_not_take};
    }
    int rob(TreeNode* root) {

        auto it = dfs(root);
        return max(it.first, it.second);
    }
};