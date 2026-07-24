class Solution {
public:
    void paint(vector<vector<int>>& A, int i, int j, vector<pair<int, int>>& q) {
        int n = A.size();
        if (i < 0 || j < 0 || i >= n || j >= n)
            return;

        if (A[i][j] != 1)
            return;

        A[i][j] = 2;
        q.push_back({i, j});
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            paint(A, i + dx[k], j + dy[k], q);
        }
    }
    int shortestBridge(vector<vector<int>>& A) {
        int n = A.size();
        vector<pair<int, int>> q;
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (A[i][j] == 1) {
                    paint(A, i, j, q);
                    found = true;
                }
            }
        }

        while (!q.empty()) {
            vector<pair<int, int>> nextLevel;
            for (auto cell : q) {
                int x = cell.first;
                int y = cell.second;
                int dx[4] = {-1, 0, 1, 0};
                int dy[4] = {0, 1, 0, -1};
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;
                    if (A[nx][ny] == 1)
                        return A[x][y] - 2;
                    if (A[nx][ny] == 0) {
                        A[nx][ny] = A[x][y] + 1;
                        nextLevel.push_back({nx, ny});
                    }
                }
            }
            q = nextLevel;
        }
        return 0;
    }
};