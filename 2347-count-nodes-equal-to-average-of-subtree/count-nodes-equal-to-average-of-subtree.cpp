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
    pair<int, int> solve(int& count, TreeNode* root) {

        if (root == nullptr) {
            return {0, 0};
        }
        auto it1 = solve(count, root->left);
        auto it2 = solve(count, root->right);

        int curr_sum =
            (it1.first + it2.first + root->val) / (it1.second + it2.second + 1);

        if (curr_sum == root->val) {
            count++;
        }

        return {it1.first + it2.first + root->val, it1.second + it2.second + 1};
    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        solve(count, root);
        return count;
    }
};