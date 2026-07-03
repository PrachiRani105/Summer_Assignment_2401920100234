class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int p_val = p->val;
        int q_val = q->val;
        
        if (p_val > q_val) {
            std::swap(p_val, q_val);
        }
        
        while (root != nullptr) {
            int root_val = root->val;
            
            if (root_val > q_val) {
                root = root->left;
            } else if (root_val < p_val) {
                root = root->right;
            } else {
                return root;
            }
        }
        
        return nullptr;
    }
};