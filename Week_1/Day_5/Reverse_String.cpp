class Solution {
public:
    void reverseString(vector<char>& s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }