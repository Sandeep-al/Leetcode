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
    int ans=INT_MIN;
    int longest(TreeNode*root,int curr){

            if(root->val!=curr) return 0;
            if(!root->left && !root->right) return 1;
            int left=0;
            int right=0;
            if(root->left) left= longest(root->left,curr);
            if(root->right) right= longest(root->right,curr);
            ans=max(ans,left+right+1);
            return 1+max(left,right);



    }
    int longestUnivaluePath(TreeNode* root) {
         if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
       

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            longest(it,it->val);

            if (it->left)
                q.push(it->left);
            if (it->right)
                q.push(it->right);
        }
        if(ans==INT_MIN) return 0;
        return ans-1;
    }
        
    
};