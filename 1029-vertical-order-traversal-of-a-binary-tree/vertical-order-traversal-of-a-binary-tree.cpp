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
    vector<tuple<int, int, int>> ans;
    void dfs(int x, int y, TreeNode* root) {

        if (root == nullptr)
            return;

        ans.push_back({y, x, root->val});

        dfs(x + 1, y - 1, root->left);
        dfs(x + 1, y + 1, root->right);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        dfs(0, 0, root);
        sort(ans.begin(), ans.end());
        vector<vector<int>> final_ans;

        vector<int> temp;

        int prev_col = INT_MIN;

        for (auto& it : ans) {

            int col = get<0>(it);
            int row = get<1>(it);
            int val = get<2>(it);

            if (col != prev_col) {

                if (!temp.empty()) {
                    final_ans.push_back(temp);
                }

                temp.clear();

                prev_col = col;
            }

            temp.push_back(val);
        }

        if (!temp.empty()) {
            final_ans.push_back(temp);
        }

        return final_ans;
    }
};