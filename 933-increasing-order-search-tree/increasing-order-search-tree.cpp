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
    TreeNode* newroot = nullptr;
    TreeNode* newroot1 = nullptr;
    void solve(TreeNode* root) {
        if (root == nullptr)
            return;
        solve(root->left);

        if (newroot != nullptr) {
            newroot->right = root;
            root->left = nullptr;
            newroot = root;

        } else {
            newroot1 = newroot = root;
            newroot->left = nullptr;
        }

        solve(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        solve(root);
        return newroot1;
    }
};