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
    int solve(int left, TreeNode* root) {
        if (root == nullptr)
            return 0;
        if ((left==1) && root->left == nullptr && root->right == nullptr) {
            return root->val;
        }

        return solve(0,root->right)+solve(1,root->left);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(-1,root);
    }
};