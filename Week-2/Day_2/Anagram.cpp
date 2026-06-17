class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<int> result;
        int s_len = s.length();
        int p_len = p.length();
        
        if (s_len < p_len) return result;
        
        int counts[26] = {0};
        int unique_chars = 0;
          for(char c:p){
            if (counts[c - 'a'] == 0) {
                unique_chars++; 
            }
            counts[c - 'a']++;
        }
        
        int match_count = 0;
        
        for (int i = 0; i < s_len; i++) {

            int right_char = s[i] - 'a';
            counts[right_char]--;
            if (counts[right_char] == 0) {
                match_count++;
            }
            
            if (i >= p_len) {
                int left_char = s[i - p_len] - 'a';
                if (counts[left_char] == 0) {
                    match_count--;
                }
                counts[left_char]++;
            }
            
            if (match_count == unique_chars) {
                result.push_back(i - p_len + 1);
            }
        }
        
        return result;
