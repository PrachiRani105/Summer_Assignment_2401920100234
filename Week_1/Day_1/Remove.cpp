class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // If the array is empty, there are 0 unique elements
        if (nums.empty()) {
            return 0;
        }
        int insertIndex = 1; 
        for(int i=1; i< nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[insertIndex] = nums[i]; 
                insertIndex++;              
            }
        }
        return insertIndex; 
    }
};