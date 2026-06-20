class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        
        for (int len = n / 2; len >= 1; len--) {
            if (n % len == 0) {
                bool match = true;
                
                for (int i = len; i < n; i += len) {
                    if (s.compare(i, len, s, 0, len) != 0) {
                        match = false;
                        break;
                    }
                }
                if (match) return true;
            }
        }
        return false;
    }
};