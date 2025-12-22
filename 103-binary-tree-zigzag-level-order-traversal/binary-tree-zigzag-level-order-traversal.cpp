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
        vector<vector<int>> final_ans;
        queue<TreeNode*> st;

        if (root != nullptr) {
            st.push(root);
        }

        int left_to_right = 1;

        while (st.size() > 0) {
            int x = st.size();
            vector<int> temp_vec;

            for (int i = 0; i < x; i++) {
                TreeNode* temp = st.front();

                if (temp->left) {
                    st.push(temp->left);
                }
                if (temp->right) {
                    st.push(temp->right);
                }

                temp_vec.push_back(temp->val);
                st.pop();
            }
            if (!left_to_right) {
                reverse(temp_vec.begin(), temp_vec.end());
            }
            final_ans.push_back(temp_vec);
            left_to_right = 1 - left_to_right;
        }

        return final_ans;
    }
};