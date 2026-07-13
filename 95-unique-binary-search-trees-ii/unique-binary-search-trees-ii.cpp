class Solution {
public:
    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> ans;
        
        if (start > end) {
            ans.push_back(nullptr);
            return ans;
        }
        
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftSubtrees = generate(start, i - 1);
            vector<TreeNode*> rightSubtrees = generate(i + 1, end);
            
            for (TreeNode* leftNode : leftSubtrees) {
                for (TreeNode* rightNode : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftNode;
                    root->right = rightNode;
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n);
    }
};