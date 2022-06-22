class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i<m; i++){
            if(grid[i][0]==0){
                for(int j = 0; j<n; j++){
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        
        for(int j = 0; j<n; j++){
            int one = 0;
            for(int i = 0; i<m; i++){
                if(grid[i][j]==1)one++;
            }
            if(one <= m/2){
                for(int i = 0; i<m; i++){
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        
        
        int sum = 0;
        for(int i = 0; i<m; i++){
            int value =0;
            for(int j = 0; j< n; j++){
                if(grid[i][j]){
                    value+= pow(2, n-j-1);
                }
            }
            sum+= value;
        }
        return sum;
    }
};