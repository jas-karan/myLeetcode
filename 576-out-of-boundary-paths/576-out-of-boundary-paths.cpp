class Solution {
public:
    int dir[4][2]= {{-1,0},{0,-1},{0,1},{1,0}};
    int dp[50][50][51];
    
    int dfs(int m,int n,int moves,int r,int c){
        if(r<0||c<0||r>=m||c>=n) return 1;
        
        if(moves==0) return 0;
        
        if(dp[r][c][moves]!=-1) return dp[r][c][moves];
        int ans=0;
        
        for(int i=0;i<4;i++){
            ans=(ans+dfs(m,n,moves-1,r+dir[i][0],c+dir[i][1]))%1000000007;;
        }
        
        return dp[r][c][moves]=ans;
    }
    
    int findPaths(int m, int n, int moves, int r, int c) {
        memset(dp,-1,sizeof(dp));
        return dfs(m,n,moves,r,c);
    }
};