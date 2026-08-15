class Solution {
    vector<int> primes{2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                       43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 
                       103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 
                       157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
    vector<int> cc(int n) {
        vector<int> fac(200, 0);
        for (int p : primes) {
            int curr = p;
            while (curr <= n) {
                fac[p] += n / curr;
                curr *= p;
            }
        }
        return fac;
    }

public:
    int uniquePaths(int m, int n) {
        vector<int> a = cc(m - 1);
        vector<int> b = cc(n - 1);
        vector<int> c = cc(m + n - 2);

        int ans = 1;
        for (int p : primes) {
            int count = c[p] - a[p] - b[p];
            for (int j = 0; j < count; j++) {
                ans *= p;
            }
        }

        return ans;
    }
};