class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        int n = nums.size();
        const long long mod = 1e9 + 7;
        vector<long long> pre(n + 1);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + nums[i];
        vector<pair<int, int>> fac;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int d = 1; d * d <= x; d++) {
                if (x % d) continue;
                if (d > 1)
                    fac.push_back({d, i});
                int y = x / d;
                if (y != d && y > 1)
                    fac.push_back({y, i});
            }
        }

        long long best = LLONG_MIN;
        int k = -1;

        if (fac.empty()) {
            long long cur = 0, mx = LLONG_MIN;

            for (int x : nums) {
                cur -= x;
                mx = max(mx, cur);
                cur = max(0LL, cur);
            }

            best = mx;
            k = 2;
        } 
        else {
            sort(fac.begin(), fac.end());
            int i = 0, m = fac.size();
            while (i < m) {
                int curK = fac[i].first;
                long long sum = 0;
                long long mn = LLONG_MAX;
                long long curBest = LLONG_MIN;
                while (i < m && fac[i].first == curK) {
                    int idx = fac[i].second;
                    mn = min(mn, sum - pre[idx]);
                    sum += 2LL * nums[idx];
                    curBest = max(curBest,
                                  sum - pre[idx + 1] - mn);

                    i++;
                }
                if (curBest > best || (curBest == best && curK < k)) {
                    best = curBest;
                    k = curK;
                }
            }
        }
        long long ans = (best % mod) * (k % mod) % mod;
        if (ans < 0) ans += mod;
        return ans;
    }
};