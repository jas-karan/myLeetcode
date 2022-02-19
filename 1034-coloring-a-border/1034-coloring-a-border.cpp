class Solution {
public:
    void helper(vector<vector<int>>& grid, int r, int c,int from){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]!=from)
            return;
        
        grid[r][c]*=-1;
        
        helper(grid,r+1,c,from);
        helper(grid,r,c+1,from);
        helper(grid,r-1,c,from);
        helper(grid,r,c-1,from);
        
        return ;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<int>>t(grid);
        helper(t,row,col,grid[row][col]);
        //get the connected component as negatives
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(t[i][j]<0){  //candidate of border
                    if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1)
                        grid[i][j]=color;
                    else if(t[i+1][j]>0 || t[i-1][j]>0 || t[i][j+1]>0 || t[i][j-1]>0) grid[i][j]=color;
                }
            }
        }
        
        return grid;
    }
};