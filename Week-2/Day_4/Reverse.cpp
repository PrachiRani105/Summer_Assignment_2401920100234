class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int start = 0;

        for (int end = 0; end <= n; ++end) {
            // When a space or end of string is reached, reverse the current segment
            if (end == n || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
        return s;
    }
};