class Solution {
public:
    bool call(int i,int j,int m,int n,vector<vector<char>>&board,int ind,string word){
	    if(ind==word.length()) return true;
	
	    if(i<0 || j<0 || i>=m || j>=n || board[i][j]!=word[ind]) return false;
	
	    char cw = board[i][j];
	    board[i][j]='$';
	    bool d = call(i+1,j,m,n,board,ind+1,word);
	    bool u = call(i-1,j,m,n,board,ind+1,word);
	    bool l = call(i,j+1,m,n,board,ind+1,word);
	    bool r = call(i,j-1,m,n,board,ind+1,word);
	
	    board[i][j] = cw;
	    return d||u||l||r;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(),n = board[0].size();
	    for(int i=0;i<m;i++){
		    for(int j=0;j<n;j++){
			    if(board[i][j]==word[0]){
			    	if(call(i,j,m,n,board,0,word))
		    			return true;
		    	}
		    }
	    }
	
	    return false;
    }
};