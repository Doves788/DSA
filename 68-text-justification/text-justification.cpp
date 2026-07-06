class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;
        while (i < n) {
            int j = i;
            int totalCharacters = 0;
            while (j < n &&
                   totalCharacters + words[j].size() + (j - i) <= maxWidth) {
                totalCharacters += words[j].size();
                j++;
            }
            int wordCount = j - i;
            int totalSpaces = maxWidth - totalCharacters;
            string line;
            if (j == n || wordCount == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) {
                        line += ' ';
                    }
                }
                line += string(maxWidth - line.size(), ' ');
            } 
            else {
                int gaps = wordCount - 1;
                int spacesPerGap = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j - 1; k++) {
                    line += words[k];
                    line += string(spacesPerGap + (k - i < extraSpaces), ' ');
                }

                line += words[j - 1];
            }
            result.push_back(line);
            i = j;
        }
        return result;
    }
};