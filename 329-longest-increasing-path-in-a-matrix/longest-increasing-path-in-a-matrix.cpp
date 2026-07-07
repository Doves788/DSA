#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int m, n;
    const int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    int dfs(const vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& memo) {
        if(memo[r][c] != 0) {
            return memo[r][c];
        }

        int max_path = 1;

        for(int i = 0; i < 4; i++) {
            int next_r = r + dirs[i][0];
            int next_c = c + dirs[i][1];

            if(next_r >= 0 && next_r < m &&
               next_c >= 0 && next_c < n &&
               matrix[next_r][next_c] > matrix[r][c]) {

                max_path = max(max_path, 1 + dfs(matrix, next_r, next_c, memo));
            }
        }

        memo[r][c] = max_path;
        return max_path;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> memo(m, vector<int>(n, 0));

        int longest_path = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                longest_path = max(longest_path, dfs(matrix, i, j, memo));
            }
        }

        return longest_path;
    }
};