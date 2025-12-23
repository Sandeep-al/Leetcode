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
    vector<tuple<int, int, int>> final_ans;
    // col row val
    void giveid(TreeNode* root, int row, int col) {

        if (root == nullptr) {
            return;
        }

        final_ans.push_back({col, row, root->val});
        giveid(root->left, row + 1, col - 1);
        giveid(root->right, row + 1, col + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        giveid(root, 0, 0);
        sort(final_ans.begin(), final_ans.end());
        vector<vector<int>>ans;

        for (int i = 0; i < final_ans.size(); i++) {

            auto [col, row, val] = final_ans[i];

            if (ans.empty() || get<0>(final_ans[i - 1]) != col) {
                ans.push_back({val});
            } else {

                ans.back().push_back(val);
            }
        }

        return ans;
    }

};