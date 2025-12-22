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
    vector<int>final_ans;

    void compute(TreeNode*root){

        if(root==nullptr){
            return;
        }

         final_ans.push_back(root->val);
        compute(root->left);
       
        compute(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {

        compute(root);
        return final_ans;
        
    }
};