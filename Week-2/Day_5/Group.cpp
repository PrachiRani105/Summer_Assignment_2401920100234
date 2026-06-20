class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = strs.size();
        if (n == 0) return {};

        
        vector<pair<string, int>> sortedTracker(n);

        for (int i = 0; i < n; i++) {
            
            sortedTracker[i].first = strs[i];
            
            
            int freq[26] = {0};
            for (char c : sortedTracker[i].first) {
                freq[c - 'a']++;
            }
            int idx = 0;
            for (int j = 0; j < 26; j++) {
                while (freq[j] > 0) {
                    sortedTracker[i].first[idx++] = 'a' + j;
                    freq[j]--;
                }
            }
            sortedTracker[i].second = i;
        }

        sort(sortedTracker.begin(), sortedTracker.end());

        vector<vector<string>> result;
        result.reserve(n); 

        vector<string> currentGroup;
        currentGroup.push_back(move(strs[sortedTracker[0].second]));

        for (int i = 1; i < n; i++) {
            if (sortedTracker[i].first == sortedTracker[i - 1].first) {
                currentGroup.push_back(move(strs[sortedTracker[i].second]));
            } else {
                result.push_back(move(currentGroup));
                currentGroup.push_back(move(strs[sortedTracker[i].second]));
            }
        }
        result.push_back(move(currentGroup));

        return result;
    }
};