class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int next_greater[10001];
        
        
        int st[1005];
        int top = 0;
        
        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];
            
            
            while (top > 0 && st[top - 1] <= num) {
                top--;
            }
            
            
            next_greater[num] = (top == 0) ? -1 : st[top - 1];
            
            // Push current number to the stack
            st[top++] = num;
        }
        
       
        vector<int> ans(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            ans[i] = next_greater[nums1[i]];
        }
        
        return ans;
    }
};