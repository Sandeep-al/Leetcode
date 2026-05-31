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
    int final_ans = 1;
    pair<int, int> dfs(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {

            return {1, 1};
        }

        int left1 = 0;
        int right1 = 0;

        if (root->left) {
            auto it = dfs(root->left);
            left1=it.first;
            right1=it.second;
        }

        int left2 = 0;
        int right2 = 0;

        if (root->right) {
            auto it = dfs(root->right);
            left2=it.first;
            right2=it.second;
        }

        int leftpath = 0;
        int rightpath = 0;

        if (root->left ) {
            leftpath = right1;
        }

        if (root->right ) {
            rightpath = left2;
        }

        final_ans = max(final_ans, max(leftpath+1,rightpath+1));

        return {leftpath+1, rightpath+1};
    }
    int longestZigZag(TreeNode* root) {

        dfs(root);
        return final_ans - 1;
    }
};