#include <vector>
#include <unordered_map>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        
        std::unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        
        int preorderIndex = 0;
        return arrayToTree(preorder, preorderIndex, 0, inorder.size() - 1, inorderMap);
    }

private:
    TreeNode* arrayToTree(const std::vector<int>& preorder, int& preorderIndex, 
                          int inorderStart, int inorderEnd, 
                          const std::unordered_map<int, int>& inorderMap) {
        // Base case: if there are no elements to construct the subtree
        if (inorderStart > inorderEnd) {
            return nullptr;
        }

       
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);

        
        int rootIndexInInorder = inorderMap.at(rootValue);

        
        root->left = arrayToTree(preorder, preorderIndex, inorderStart, rootIndexInInorder - 1, inorderMap);
        root->right = arrayToTree(preorder, preorderIndex, rootIndexInInorder + 1, inorderEnd, inorderMap);

        return root;
    }
};