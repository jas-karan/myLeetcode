class Solution {
public:
    int m,n;
    
    int dfs(int r,int c,vector<vector<int>>& grid){
        if(r==m) return c;
        
        if(grid[r][c]==1){
            if(c+1<n && grid[r][c+1]==1) return dfs(r+1,c+1,grid);
            else return -1;
        }
        if(grid[r][c]==-1){
            if(c>0 && grid[r][c-1]==-1) return dfs(r+1,c-1,grid);
            else return -1;
        }
        
        return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        
        vector<int>col;
        for(int j=0;j<n;j++){
            col.push_back(dfs(0,j,grid));
        }
        
        return col;
    }
};