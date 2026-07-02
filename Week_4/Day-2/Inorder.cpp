class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        
        // Lambda function for recursion
        auto dfs = [&](auto& self, TreeNode* node) -> void {
            if (!node) return;
            self(self, node->left);
            result.push_back(node->val);
            self(self, node->right);
        };
        
        dfs(dfs, root);
        return result;
    }
};