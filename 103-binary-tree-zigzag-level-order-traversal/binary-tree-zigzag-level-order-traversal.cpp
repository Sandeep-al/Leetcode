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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;
        q.push(root);

        int gear = 0; //  left to right
        while (!q.empty()) {
            
            int x=q.size();
            vector<int> temp;
            for (int i = 0; i<x; i++) {
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);

                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }

            if (gear) {
                reverse(temp.begin(), temp.end());
            }

            ans.push_back(temp);
            gear = 1 - gear;
        }

        return ans;
    }
};