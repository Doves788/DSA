
class Solution {
public:
    vector<string> result;

    bool isValid(string &s) {
        if (s.size() > 1 && s[0] == '0') return false;
        int val = stoi(s);
        return val >= 0 && val <= 255;
    }

    void backtrack(string &s, int index, int dots, string curr) {
        if (dots == 4 && index == s.size()) {
            curr.pop_back();
            result.push_back(curr);
            return;
        }

        if (dots > 4) return;

        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {
            string part = s.substr(index, len);
            if (isValid(part)) {
                backtrack(s, index + len, dots + 1, curr + part + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        result.clear();
        backtrack(s, 0, 0, "");
        return result;
    }
};