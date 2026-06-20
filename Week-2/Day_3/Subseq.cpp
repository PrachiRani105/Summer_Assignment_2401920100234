class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        
        int s_ptr = 0;
        int s_len = s.length();
        
        for (char c : t) {
            if (c == s[s_ptr]) {
                s_ptr++;
                if (s_ptr == s_len) {
                    return true;
                }
            }
        }
        
        return false;
    }
};