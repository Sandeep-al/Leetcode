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
    int findSecondMinimumValue(TreeNode* root) {
        queue<TreeNode*> q;
        int x = root->val;
        long long mini=1LL*INT_MAX+1LL*1;
        q.push(root);

        while (!q.empty()) {

            auto node = q.front();
            q.pop();
            if ((node->val) > x) {

                mini=min(mini,1LL*node->val);
            }

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        return mini==1LL*INT_MAX+1LL*1?-1:mini;
    }
};