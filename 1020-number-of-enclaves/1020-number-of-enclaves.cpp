class Solution {
public:
    void helper(vector<vector<int>>&grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1) return;
        
        grid[i][j]=-1;
        
        helper(grid,i+1,j);
        helper(grid,i-1,j);
        helper(grid,i,j+1);
        helper(grid,i,j-1);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[i][0]==1) helper(grid,i,0);
            if(grid[i][n-1]==1) helper(grid,i,n-1);
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]==1) helper(grid,0,j);
            if(grid[m-1][j]==1) helper(grid,m-1,j);
        }
        
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) count++;
            }
        }
        
        return count;
    }
};