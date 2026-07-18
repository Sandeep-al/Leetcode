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
    TreeNode * solve(TreeNode* root){
        if(root==nullptr){
            return nullptr;
        }

        auto left_n=solve(root->left);
        auto right_n=solve(root->right);

        root->left=right_n;
        root->right=left_n;

        return root;

        
    }
    TreeNode* invertTree(TreeNode* root) {
        return solve(root);
    }
};