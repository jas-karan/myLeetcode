class Solution {
public:
    int m,n;
    int memo[72][72][72];
    vector<int> dir={-1,1,0};
    
    int dfs(vector<vector<int>>&grid,int r,int c1,int c2){
        if(r==m || c1<0 || c1>=n || c2<0 || c2>=n) return INT_MIN;
        
        if(memo[r][c1][c2]!=-1) return memo[r][c1][c2];
        
        int ans = grid[r][c1];
        if(c1!=c2) ans+=grid[r][c2];
        
        int t=0;
        for(int i=0;i<3;i++)
         {
            for(int j=0;j<3;j++)
            {
                t = max(t, dfs(grid,r+1, c1 + dir[i], c2+dir[j]));
            }
         }
        
        return memo[r][c1][c2]=ans+t;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size(),n=grid[0].size();
        memset(memo,-1,sizeof(memo));
        return dfs(grid,0,0,n-1);
    }
};