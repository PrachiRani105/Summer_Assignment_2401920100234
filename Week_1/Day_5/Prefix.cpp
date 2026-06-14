#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (strs.empty()) return "";
        
        sort(strs.begin(), strs.end());
        
        string first = strs[0];
        string last = strs[strs.size() - 1];
        
        string result = "";
        
        for (int i = 0; i < min(first.length(), last.length()); i++) {
            if (first[i] != last[i]) {
                break; 
            }
            result += first[i];
        }
        
        return result;
    }
};