class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>mem(m,vector<int>(n,0));
        
        mem[0][0] = grid[0][0]==1 ? 0:1;
        for(int j=1;j<n;j++){
            mem[0][j] = grid[0][j]==1 ? 0 : mem[0][j-1];
        }
        for(int i=1;i<m;i++){
            mem[i][0] = grid[i][0]==1 ? 0 : mem[i-1][0];
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]==1) continue;
                mem[i][j] = mem[i-1][j] + mem[i][j-1];
            }
        }
        
        return mem[m-1][n-1];
    }
};