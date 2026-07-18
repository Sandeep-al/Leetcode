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
    bool ans = false;
    TreeNode* subtree;
    bool issubtree(TreeNode* root, TreeNode* subtree) {
        if (root == nullptr && subtree == nullptr) {
            return 1;
        }

        if (root == nullptr || subtree == nullptr) {
            return false;
        }

        if (root->val != subtree->val) {
            return false;
        }

        return issubtree(root->left, subtree->left) && issubtree(root->right, subtree->right);
    }
    void solve(TreeNode* root, int x) {
        if (root==nullptr)
            return;

        if (root->val == x) {
            ans = ans || issubtree(root, subtree);
        }

        solve(root->left,x);
        solve(root->right,x);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        this->subtree = subRoot;
        solve(root, subtree->val);
        return ans;
    }
};