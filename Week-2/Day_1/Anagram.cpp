class Solution {
public:
    bool isAnagram(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if (s.length() != t.length()) {
            return false;
        }
        
        int count[26] = {0};
        int len = s.length(); 
        
        for (int i = 0; i < len; ++i) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};