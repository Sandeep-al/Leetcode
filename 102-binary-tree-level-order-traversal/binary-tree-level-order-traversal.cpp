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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if (root) {
            q.push(root);
        }

        while (q.size() > 0) {
            int x = q.size();
            vector<int> temp;
            for (int i = 0; i < x; i++) {
                TreeNode* current = q.front();
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }

                temp.push_back(current->val);
                q.pop();
            }

            ans.push_back(temp);
        }

        return ans;
    }
};