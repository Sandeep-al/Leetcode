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
    int final_ans = 0;
    void dfs(TreeNode* root, int maxi, int mini) {

        if (root == nullptr) {
            final_ans = max(final_ans, abs(maxi - mini));
            return;
        }

        maxi = max(maxi, root->val);
        mini = min(mini, root->val);

        dfs(root->left, maxi, mini);
        dfs(root->right, maxi, mini);
    }
    int maxAncestorDiff(TreeNode* root) {

        dfs(root,INT_MIN,INT_MAX);
        return final_ans;
    }
};