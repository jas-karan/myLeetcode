class Solution {
public:
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    
    bool find(vector<vector<char>>&board,int i,int j,int m,int n,string &word,int ind){
        if(ind==word.length()) return true;
        
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]!=word[ind]) return false;
        
        char c = board[i][j];
        board[i][j] = '$';
        
        bool ans = false;
        for(int d=0;d<4;d++){
            int x = i+dir[d][0], y = j+dir[d][1];
            ans = ans||find(board,x,y,m,n,word,ind+1);
        }
        
        board[i][j]=c;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(find(board,i,j,m,n,word,0)) return true;
                }
            }
        }
        
        return false;
    }
};