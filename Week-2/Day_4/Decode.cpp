class Solution {
public:
    string decodeString(string s) {
        vector<pair<int, string>> stack;
        string currentString = "";
        int k = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');
            } else if (ch == '[') {
                
                stack.push_back({k, currentString});
                currentString = "";
                k = 0;
            } else if (ch == ']') {
                auto [repeatTimes, prevString] = stack.back();
                stack.pop_back();
                
                string repeated = "";
                while (repeatTimes-- > 0) {
                    repeated += currentString;
                }
                currentString = prevString + repeated;
            } else {
                currentString += ch;
            }
        }

        return currentString;
    }
};