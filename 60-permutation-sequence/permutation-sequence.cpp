class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n + 1, 1), vec;
        
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
            vec.push_back(i);
        }

        k--; 
        string ans = "";

        for (int i = n; i >= 1; i--) {
            int f = fact[i - 1];
            int x = k / f;
            ans += to_string(vec[x]);
            vec.erase(vec.begin() + x);
            k %= f;
        }

        return ans;
    }
};