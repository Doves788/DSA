class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int M = matrix.size();
        int N = matrix[0].size();

        vector<vector<int>> mat(M, vector<int>(N));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                mat[i][j] = matrix[i][j] - '0';
            }
        }
        for (int i = 0; i < M; i++) {
            for (int j = 1; j < N; j++) {
                if (mat[i][j] == 1) {
                    mat[i][j] += mat[i][j - 1];
                }
            }
        }

        int Ans = 0;

        for (int j = 0; j < N; j++) {
            for (int i = 0; i < M; i++) {
                int width = mat[i][j];
                if (width == 0) continue;
                int currWidth = width;
                for (int k = i; k < M && mat[k][j] > 0; k++) {
                    currWidth = min(currWidth, mat[k][j]);
                    int height = k - i + 1;
                    Ans = max(Ans, currWidth * height);
                }
                currWidth = width;
                for (int k = i; k >= 0 && mat[k][j] > 0; k--) {
                    currWidth = min(currWidth, mat[k][j]);
                    int height = i - k + 1;
                    Ans = max(Ans, currWidth * height);
                }
            }
        }

        return Ans;
    }
};