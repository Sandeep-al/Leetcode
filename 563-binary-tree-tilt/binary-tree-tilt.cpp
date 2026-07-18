/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int total=0;
    int solve(TreeNode* root) {
        if(root==nullptr) return 0;

        int right=solve(root->right);
        int left=solve(root->left);
        int diff=abs(left-right);

        total+=diff;

        return root->val+left+right;
    }
    int findTilt(TreeNode* root){
        solve(root);
        return total;
    }
};