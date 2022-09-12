class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10]={0};
        int col[9][10]={0};
        int block[3][3][10]={0};
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int num = board[i][j]-'0';
                
                if(row[i][num]++) return false;
                if(col[j][num]++) return false;
                if(block[i/3][j/3][num]++) return false;
            }
        }
        
        return true;
    }
};