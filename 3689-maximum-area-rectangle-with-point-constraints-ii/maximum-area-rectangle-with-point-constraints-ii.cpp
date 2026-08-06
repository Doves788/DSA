class Solution {
public:
    long long maxRectangleArea(vector<int>& xC, vector<int>& yC) {
        long long maxArea = -1;
        const int N = yC.size();
        set<tuple<int, int, int>> baselines; 
        vector<int> byYX(N);
        ranges::iota(byYX, 0);
        ranges::sort(byYX, [&](auto i, auto j) { 
            if (yC[i] < yC[j]) return true;
            else if (yC[i] == yC[j] && xC[i] < xC[j]) return true;
            return false;
        });
        long long ans = -1;
        int l = 0;
        while (l < N) {
            const int y = yC[byYX[l]];
            int r = l+1;
            while (r < N && yC[byYX[r]] == y) ++r;
            for (int k = l+1; k < r; ++k) {
                const int xi = xC[byYX[k-1]];
                const int xj = xC[byYX[k]];
                auto it = baselines.lower_bound({xi, xj, 0});
                if (it == end(baselines)) continue;
                const auto [a, b, yp] = *it;
                if (xi == a && xj == b) ans = max(ans, 1LL*(xj-xi)*(y-yp));
            }
            for (int k = l; k < r; ++k) {
                const int x = xC[byYX[k]];
                while (true) {
                    auto it = baselines.upper_bound({x+1, 0, 0}); 
                    if (it == begin(baselines)) break;
                    --it;
                    const auto [px1, px2, py] = *it;
                    if (px1 <= x && x <= px2) {
                        
                        baselines.erase(it);
                    }
                    else break;
                }
            }

            for (int k = l+1; k < r; ++k) {
                const int xi = xC[byYX[k-1]];
                const int xj = xC[byYX[k]];
                baselines.emplace(xi, xj, y);
            }
            l = r;
        }

        return ans;
    }
};