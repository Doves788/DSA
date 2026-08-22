class Solution {
public:
    vector<vector<int>> adj;
    vector<int> par, bt;
    int ans = INT_MIN;

    void findParent(int u, int p) {
        par[u] = p;

        for (int v : adj[u]) {
            if (v == p) continue;
            findParent(v, u);
        }
    }

    void dfs(int u, int p, int t, int money, vector<int>& amount) {
        if (t < bt[u]) {
            money += amount[u];
        } 
        else if (t == bt[u]) {
            money += amount[u] / 2;
        }

        bool leaf = true;

        for (int v : adj[u]) {
            if (v == p) continue;

            leaf = false;
            dfs(v, u, t + 1, money, amount);
        }

        if (leaf) {
            ans = max(ans, money);
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int n = amount.size();

        adj.resize(n);
        par.resize(n);
        bt.assign(n, INT_MAX);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        findParent(0, -1);

        int u = bob;
        int t = 0;

        while (u != -1) {
            bt[u] = t;
            u = par[u];
            t++;
        }
        dfs(0, -1, 0, 0, amount);
        return ans;
    }
};