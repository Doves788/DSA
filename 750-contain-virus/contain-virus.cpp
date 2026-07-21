#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> par, rank;

public:
    DSU(int n) {
        par.resize(n);
        rank.resize(n, 0);
        iota(par.begin(), par.end(), 0);
    }

    int find_set(int u) {
        if (par[u] == u) 
            return u;
        return par[u] = find_set(par[u]);
    }

    void union_sets(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u != v) {
            if (rank[u] < rank[v]) swap(u, v);
            par[v] = u;
            if (rank[u] == rank[v]) rank[u]++;
        }
    }
};

class Solution {
    int n, m;

    inline static const int di[4] = {0, 1, 0, -1};
    inline static const int dj[4] = {1, 0, -1, 0};
    int virusContainer(vector<vector<int>>& isInfected, DSU& d) {
        unordered_map<int, pair<int, unordered_set<int>>> adj;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isInfected[i][j] == 1) {
                    int root = d.find_set(i * m + j);
                    for (int k = 0; k < 4; k++) {
                        int ni = i + di[k];
                        int nj = j + dj[k];
                        if (ni < 0 || nj < 0 || ni >= n || nj >= m) 
                            continue;
                        int loc = ni * m + nj;
                      
                        if (isInfected[ni][nj] == 0) {
                         
                            if (adj[root].second.empty())
                                adj[root].first = 0;
                            adj[root].first++;
                            adj[root].second.insert(loc);
                        }
                    }
                }
            }
        }

        if (adj.empty()) 
            return 0;
        int targetRoot = 0;
        size_t maxFrontierSize = 0;
        for (auto& [root, data] : adj) {
            auto& [wallsNeeded, frontierSet] = data;
            if (frontierSet.size() > maxFrontierSize) {
                maxFrontierSize = frontierSet.size();
                targetRoot = root;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isInfected[i][j] == 1) {
                    int root = d.find_set(i * m + j);
                    if (root == targetRoot) 
                        continue;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + di[k];
                        int nj = j + dj[k];
                        if (ni < 0 || nj < 0 || ni >= n || nj >= m) 
                            continue;
                        if (isInfected[ni][nj] == 0)
                            isInfected[ni][nj] = -1;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isInfected[i][j] == 1 && d.find_set(i * m + j) == targetRoot) {
                    isInfected[i][j] = -2;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isInfected[i][j] == 1 || isInfected[i][j] == -1) {
                    int root = d.find_set(i * m + j);
                    for (int k = 0; k < 4; k++) {
                        int ni = i + di[k];
                        int nj = j + dj[k];
                        if (ni<0||nj<0||ni>=n||nj>=m) continue;
                        if (isInfected[ni][nj] == 1 || isInfected[ni][nj] == -1) {
                            d.union_sets(ni*m + nj, root);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isInfected[i][j] == -1)
                    isInfected[i][j] = 1;
            }
        }
        return adj[targetRoot].first + virusContainer(isInfected, d);
    }

public:
    int containVirus(vector<vector<int>>& isInfected) {
        n = isInfected.size();
        m = isInfected[0].size();
        DSU d(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isInfected[i][j] == 1) {
                    int id1 = i * m + j;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + di[k];
                        int nj = j + dj[k];
                        if (ni < 0 || nj < 0 || ni >= n || nj >= m) 
                            continue;
                        if (isInfected[ni][nj] == 1) {
                            int id2 = ni * m + nj;
                            d.union_sets(id1, id2);
                        }
                    }
                }
            }
        }

        
        return virusContainer(isInfected, d);
    }
};