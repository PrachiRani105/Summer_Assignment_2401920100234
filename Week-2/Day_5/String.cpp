class Solution {
public:
    int compress(vector<char>& chars) {
       
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = chars.size();
        int writeIdx = 0; 
        int readIdx = 0;  

        while (readIdx < n) {
            char currentChar = chars[readIdx];
            int count = 0;

            while (readIdx < n && chars[readIdx] == currentChar) {
                readIdx++;
                count++;
            }

            chars[writeIdx++] = currentChar;

            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[writeIdx++] = c;
                }
            }
        }

        return writeIdx;
    }
};