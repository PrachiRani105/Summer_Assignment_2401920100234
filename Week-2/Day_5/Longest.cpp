class Solution {
public:
    string longestPalindrome(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        if (n <= 1) return s;

        string t;
        t.reserve(2 * n + 3);
        t += '^';
        for (char c : s) {
            t += '#';
            t += c;
        }
        t += "#$";

        int m = t.length();
        vector<int> P(m, 0);
        int C = 0, R = 0; 

        int maxLen = 0;
        int centerIndex = 0;

        for (int i = 1; i < m - 1; i++) {
            int i_mirror = 2 * C - i;

            if (R > i) {
                P[i] = min(R - i, P[i_mirror]);
            }

            
            while (t[i + 1 + P[i]] == t[i - 1 - P[i]]) {
                P[i]++;
            }

            
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }

            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }

        
        int start = (centerIndex - 1 - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};