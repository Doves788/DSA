class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        if (k == 1)
            return n;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    if (len == 2 || dp[i + 1][j - 1])
                        dp[i][j] = true;
                }
            }
        }

        int ans = 0;
        int i = 0;

        while (i <= n - k) {
            if (dp[i][i + k - 1]) {
                ans++;
                i += k;
            }
            else if (i + k < n && dp[i][i + k]) {
                ans++;
                i += k + 1;
            }
            else {
                i++;
            }
        }

        return ans;
    }
};