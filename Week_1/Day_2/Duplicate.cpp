class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seenNumbers;
        for (int i = 0; i < nums.size(); i++) {
            if (seenNumbers.find(nums[i]) != seenNumbers.end()) {
                return true; 
            }
            seenNumbers.insert(nums[i]);
        }
        return false;
    }
};