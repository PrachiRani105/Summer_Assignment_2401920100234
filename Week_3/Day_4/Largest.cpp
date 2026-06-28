class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int n = heights.size();
        
        std::vector<int> st(n + 1);
        int top = 0;
        int max_area = 0;
        
        for (int i = 0; i <= n; ++i) {
           
            int current_height = (i == n) ? 0 : heights[i];
            
           
            while (top > 0 && heights[st[top - 1]] > current_height) {
                int height = heights[st[--top]]; // Pop the top element
                
                int width = (top == 0) ? i : i - st[top - 1] - 1;
                
                max_area = std::max(max_area, height * width);
            }
            st[top++] = i;
        }
        
        return max_area;
    }
};