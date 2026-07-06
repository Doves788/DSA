class Solution {
public:
    bool ok(vector<vector<char>>& b,int r,int c,char ch){
        for(int i=0;i<9;i++){
            if(b[r][i]==ch) return false;
            if(b[i][c]==ch) return false;
        }
        int sr=(r/3)*3;
        int sc=(c/3)*3;
        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(b[i][j]==ch) return false;
            }
        }

        return true;
    }

    bool dfs(vector<vector<char>>& b){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(b[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(ok(b,i,j,ch)){
                            b[i][j]=ch;

                            if(dfs(b)) return true;

                            b[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }
};