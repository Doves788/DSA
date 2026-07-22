class Solution {
public:
    int MOD = 1e9 + 7;
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] != s[j]) {
                    dp[i][j] = ((dp[i+1][j] + dp[i][j-1]) % MOD - dp[i+1][j-1] + MOD) % MOD;
                }
                 else {
                    int low = i + 1, high = j - 1;
                    while (low <= high && s[low] != s[i]) low++;
                    while (low <= high && s[high] != s[j]) high--;
                    if (low > high) {
                        dp[i][j] = (dp[i+1][j-1] * 2 + 2) % MOD;
                    } 
                    else if (low == high) {
                        dp[i][j] = (dp[i+1][j-1] * 2 + 1) % MOD;
                    } 
                    else {
                        dp[i][j] = ((dp[i+1][j-1] * 2 - dp[low+1][high-1]) % MOD + MOD) % MOD;
                    }
                }
            }
        }

        return dp[0][n-1];
    }
};