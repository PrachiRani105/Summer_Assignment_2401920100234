class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (ransomNote.length() > magazine.length()) {
            return false;
        }
        
        int counts[26] = {0};
        
        for (char c : magazine) {
            counts[c - 'a']++;
        }
        
        for (char c : ransomNote) {
            if (--counts[c - 'a'] < 0) {
                return false; 
            }
        }
        
        return true;
    }
};