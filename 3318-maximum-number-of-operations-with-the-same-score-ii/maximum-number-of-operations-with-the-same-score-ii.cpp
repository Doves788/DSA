class Solution {
public:
    int n;
    vector<int> nums;
    vector<vector<int>> dp;
    int target;
    int solve(int i, int j) {
        if (j - i + 1 < 2) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if (i + 1 <= j && nums[i] + nums[i + 1] == target)
            ans = max(ans, 1 + solve(i + 2, j));
        if (i <= j - 1 && nums[j - 1] + nums[j] == target)
            ans = max(ans, 1 + solve(i, j - 2));
        if (nums[i] + nums[j] == target)
            ans = max(ans, 1 + solve(i + 1, j - 1));
        return dp[i][j] = ans;
    }
    int calc(int score) {
        target = score;
        dp.assign(n, vector<int>(n, -1));
        return solve(0, n - 1);
    }
    int maxOperations(vector<int>& arr) {
        nums = arr;
        n = nums.size();
        int ans = 0;
        ans = max(ans, calc(nums[0] + nums[1]));
        ans = max(ans, calc(nums[n - 2] + nums[n - 1]));
        ans = max(ans, calc(nums[0] + nums[n - 1]));
        return ans;
    }
};