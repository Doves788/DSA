class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> charPos;
    int solve(int ringPos, int keyPos, string &ring, string &key) {
        if (keyPos == key.size()) return 0;
        if (dp[ringPos][keyPos] != -1) return dp[ringPos][keyPos];
        int n = ring.size();
        int minSteps = INT_MAX;
        for (int nextPos : charPos[key[keyPos] - 'a']) {
            int dist = abs(ringPos - nextPos);
            int rotate = min(dist, n - dist);
            minSteps = min(minSteps,
                           rotate + 1 + solve(nextPos, keyPos + 1, ring, key));
        }
        return dp[ringPos][keyPos] = minSteps;
    }

    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        charPos.assign(26, {});
        for (int i = 0; i < n; i++) {
            charPos[ring[i] - 'a'].push_back(i);
        }
        dp.assign(n, vector<int>(m, -1));
        return solve(0, 0, ring, key);
    }
};