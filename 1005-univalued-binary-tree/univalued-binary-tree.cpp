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
    int x;
    bool check(TreeNode* root) {
        if (root == nullptr)
            return 1;

        return root->val == x && check(root->left) && check(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        this->x=root->val;
        return check(root);
    }
};