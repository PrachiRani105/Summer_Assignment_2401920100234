class Solution {
public:
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int status[26];
        for (int i = 0; i < 26; ++i) {
            status[i] = -1;
        }
        
        int len = s.length();
        
        for (int i = 0; i < len; ++i) {
            int charIdx = s[i] - 'a';
            if (status[charIdx] == -1) {
                status[charIdx] = i;  
            } else if (status[charIdx] >= 0) {
                status[charIdx] = -2; 
            }
        }
        
        
        int minIndex = 1e9; 
        for (int i = 0; i < 26; ++i) {
            if (status[i] >= 0 && status[i] < minIndex) {
                minIndex = status[i];
            }
        }
        
        return (minIndex == 1e9) ? -1 : minIndex;
    }
};