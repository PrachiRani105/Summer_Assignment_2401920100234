
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        calculateMaxGain(root, max_sum);
        return max_sum;
    }

private:
    int calculateMaxGain(TreeNode* node, int& max_sum) {
        if (node == nullptr) {
            return 0;
        }

        int leftGain = std::max(0, calculateMaxGain(node->left, max_sum));
        int rightGain = std::max(0, calculateMaxGain(node->right, max_sum));
        int currentPathSum = node->val + leftGain + rightGain;

        
        max_sum = std::max(max_sum, currentPathSum);

        return node->val + std::max(leftGain, rightGain);
    }
};