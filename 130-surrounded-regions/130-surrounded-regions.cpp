class Solution {
public:
    void call(vector<vector<char>>&board,int i,int j){
	    if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!='O') return;
	
	    board[i][j]='$';
	    call(board,i+1,j);call(board,i-1,j);call(board,i,j+1);call(board,i,j-1);
	}
    
    void solve(vector<vector<char>>& board) {
        int m = board.size(),n = board[0].size();
        
        //rather than finding valid cells, find invalid cells
        //first convert all cells that are reachable from boundary to $
	    //those cannot be captured
	    //then convert all left O's to X's
	
	    for(int i=0;i<m;i++) call(board,i,0);
	    for(int i=0;i<m;i++) call(board,i,n-1);
	    for(int j=0;j<n;j++) call(board,0,j);
	    for(int j=0;j<n;j++) call(board,m-1,j);
	
	    for(int i=0;i<m;i++){
		    for(int j=0;j<n;j++){
			    if(board[i][j]=='O') board[i][j]='X';
			    if(board[i][j]=='$') board[i][j]='O';
		    }
	    }
    }
};