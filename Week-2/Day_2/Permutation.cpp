class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        if (n > m) return false;

        int cnt[26] = {0};

        for (char c : s1)
            cnt[c - 'a']++;

        int left = 0, right = 0;

        while (right < m) {
            cnt[s2[right] - 'a']--;
            right++;

            while (cnt[s2[right - 1] - 'a'] < 0) {
                cnt[s2[left] - 'a']++;
                left++;
            }

            if (right - left == n)
                return true;
        }

        return false;
    }
}; 
