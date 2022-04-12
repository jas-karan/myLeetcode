class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        
        k = k%(m*n);
        
        if(k==0) return grid;
        
        vector<vector<int>>temp = grid;
        
         while(k--){
            for(int i = 0; i < n; ++i){
                for(int j = 1; j < m; ++j){
                    temp[i][j] = grid[i][j-1];
                }
                    
            }
            for(int i = 0; i < n-1; ++i){
                temp[i+1][0] = grid[i][m-1];
            }
            temp[0][0] = grid[n-1][m-1]; // special case
            grid = temp;
        }
        return temp;
    }
        
};