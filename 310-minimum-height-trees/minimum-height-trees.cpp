class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 0)
            return {};
        if (n == 1)
            return {0};
            
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1)
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty()) {
            int cnt = q.size();
            ans.clear();
            while (cnt--) {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for (int next : graph[node]) {
                    degree[next]--;
                    if (degree[next] == 1)
                        q.push(next);
                }
            }
        }
        return ans;
    }
};