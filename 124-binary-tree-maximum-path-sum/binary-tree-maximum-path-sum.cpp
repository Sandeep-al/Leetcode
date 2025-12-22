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
    int max_path_sum=INT_MIN;

    int maxd(TreeNode*root){

        if(root==nullptr){
            return 0;
        }

        int lh=maxd(root->left);
        int rh=maxd(root->right);

        max_path_sum=max(root->val,max(max_path_sum,lh+rh+root->val));

        return max(0,root->val+max(lh,rh));
    }
    int maxPathSum(TreeNode* root) {
        maxd(root);
        return max_path_sum;
    }
};