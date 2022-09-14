class Solution {
public:
    bool poss(vector<vector<char>>&b){
        int row[9][10]={0};
        int col[9][10]={0};
        int block[3][3][10]={0};
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(b[i][j]=='.') continue;
                if(row[i][b[i][j]-'0']++) return false;
                if(col[j][b[i][j]-'0']++) return false;
                if(block[i/3][j/3][b[i][j]-'0']++) return false;
            }
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>>&board,int r,int c){
        if(r==9) return true;
        if(c==9){
            return solve(board,r+1,0);
        }
        
        if(board[r][c]!='.') return solve(board,r,c+1);
        
        for(int i=1;i<=9;i++){
            board[r][c] = i+'0';
            if(poss(board) && solve(board,r,c+1)) return true;
            board[r][c] = '.';
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};