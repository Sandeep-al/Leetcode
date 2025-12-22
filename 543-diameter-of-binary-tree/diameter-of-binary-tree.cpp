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
    int maxi=0;
    int compute(TreeNode*root){
        if(root==nullptr){
            return 0;
        }

        int lh=compute(root->left);
        int rh=compute(root->right);

        maxi=max(maxi,lh+rh);

        return max(lh,rh)+1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        compute(root);
        return maxi;
    }
};