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
    int maxi = 0;
    int solve(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = 1 + solve(root->left);
        int right = 1 + solve(root->right);

        maxi = max(left + right - 1, maxi);

        return max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        solve(root);
        return maxi-1;
    }
};