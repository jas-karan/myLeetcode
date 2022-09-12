class Solution {
public:
    int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    
    void island(vector<vector<int>>&grid,int i,int j,int m,int n,int&area){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0) return ;
        
        area++;
        grid[i][j]=0;
        
        for(int d=0;d<4;d++){
            island(grid, i+dir[d][0], j+dir[d][1], m,n,area);
        }
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int currArea=0;
                    island(grid,i,j,m,n,currArea);
                    area = max(area, currArea);
                }
            }
        }
        
        return area;
    }
};