class Solution {
public:
    int curr=0;
    int m,n;
    int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    
    void dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]==0) return ;
        
        grid[i][j]=0;
        curr++;
        
        for(int k=0;k<4;k++){
            dfs(i+dir[k][0],j+dir[k][1],grid);
        }
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        m=grid.size();
        n=grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid);
                    ans=max(ans,curr);
                    curr=0;
                }
            }
        }
        
        return ans;
    }
};