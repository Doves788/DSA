class DisjointSet {
public:
    vector<int> parent, sz;
    DisjointSet(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findUPar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        u = findUPar(u);
        v = findUPar(v);
        if (u == v)
            return;
        if (sz[u] < sz[v]) {
            parent[u] = v;
            sz[v] += sz[u];
        }
        else {
            parent[v] = u;
            sz[u] += sz[v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if (connections.size() < n - 1)
            return -1;

        DisjointSet ds(n);
        int extra = 0;
        for (auto &it : connections) {
            int u = it[0];
            int v = it[1];
            if (ds.findUPar(u) == ds.findUPar(v))
                extra++;
            else
                ds.unionBySize(u, v);
        }
        int comp = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i)
                comp++;
        }
        int need = comp - 1;
        if (extra >= need)
            return need;
        return -1;
    }
};