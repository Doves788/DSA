class Solution {

    void bfs ( int r, int c, int rows, int cols,vector<vector<int>>& grid,vector<vector<int>>& visited, int k, long long& res ) {
        if ( r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0 ) return;
        queue<pair<int,int>>q;
        visited[r][c]=1;
        q.push( {r,c} );
        vector<pair<int,int>>directions = {{-1,0}, {1,0} , {0,1}, {0,-1}};
        long long sum = grid[r][c];
        while ( !q.empty() ) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for ( auto[dr,dc] : directions ) {
                int nr = row + dr;
                int nc = col + dc;
                if ( nr >= 0 && nc >= 0 && nr < rows && nc < cols && !visited[nr][nc] && grid[nr][nc] > 0 ) {
                    visited[nr][nc] = 1;
                    sum += grid[nr][nc];
                    q.push({nr,nc});
                }
            }
        }
        if ( sum % k == 0 ) res++;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited( rows, vector<int>(cols,0));
        long long res = 0;
        for ( int row = 0; row < rows; row++ ) {
            for ( int col = 0; col < cols; col++ ) {
                if ( grid[row][col] > 0 && !visited[row][col] ) {
                    bfs( row, col, rows, cols,grid, visited,k ,res );

                }
            }
        }

        return res;
    }
};