class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int m = mat.size();
        int n = mat[0].size();
        
        if (m * n != r * c) {
            return mat;
        }
        
        vector<vector<int>> result(r, vector<int>(c));
        
        int totalElements = m * n;
        for (int count = 0; count < totalElements; count++) {
            int originalRow = count / n;
            int originalCol = count % n;
            
            int newRow = count / c;
            int newCol = count % c;
            
            result[newRow][newCol] = mat[originalRow][originalCol];
        }
        
        return result;
    }
};