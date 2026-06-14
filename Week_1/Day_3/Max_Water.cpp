3include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;
        
        while (left < right) {
            int width = right - left;
            int current_height = min(height[left], height[right]);
            int current_water = current_height * width;
            
            if (current_water > max_water) {
                max_water = current_water;
            }
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};