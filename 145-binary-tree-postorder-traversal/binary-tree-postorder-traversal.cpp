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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if (root == nullptr)
            return ans;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;

        while (curr || !st.empty()) {

            while (curr != nullptr) {
                st.push(curr);

                curr = curr->left;
            }

            curr = st.top();

            if (curr->right == nullptr || curr->right == lastVisited) {
                ans.push_back(curr->val);
                st.pop();
                lastVisited = curr;
                curr = nullptr;
            } else {
                curr = curr->right;
            }
        }

        return ans;
    }
};