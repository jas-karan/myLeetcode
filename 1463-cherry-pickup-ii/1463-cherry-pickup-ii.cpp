class Solution {
private:
    int n;
    int m;
    int dp[72][72][72];
    vector<int> dir={-1,1,0};
    
public:
    int dfs(vector<vector<int>>& grid,int r,int i,int j)
    {
        if(r<0 || r>=n || i<0 || i>=m || j<0 || j>=m)return INT_MIN;
        if(dp[r][i][j]!=-1)return dp[r][i][j];
        int res=0;
        res=(i==j)?grid[r][j]:grid[r][i]+grid[r][j]; 
         int temp=0;
         for(int k=0;k<3;k++)
         {
            for(int t=0;t<3;t++)
            {
                temp = max(temp, dfs(grid,r+1, i + dir[k], j+dir[t]));
            }
         }
         
        return dp[r][i][j]=res+temp;
        
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return dfs(grid,0,0,m-1);
        
    }
};