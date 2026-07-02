
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        
        bool leftToRight = true;
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel(levelSize); 
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = q.front();
                q.pop();
                
                
                int index = leftToRight ? i : (levelSize - 1 - i);
                currentLevel[index] = currentNode->val;
                
                if (currentNode->left) q.push(currentNode->left);
                if (currentNode->right) q.push(currentNode->right);
            }
            
           
            leftToRight = !leftToRight;
            
            
            result.push_back(move(currentLevel));
        }
        
        return result;
    }
};