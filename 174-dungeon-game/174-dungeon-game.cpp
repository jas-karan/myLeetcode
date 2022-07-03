class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>need(m+1,vector<int>(n+1,INT_MAX));
        
        need[m][n-1]=need[m-1][n]=1;
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int t = min(need[i][j+1],need[i+1][j])-grid[i][j];
                need[i][j] = t<=0 ? 1:t;
            }
        }
        
        return need[0][0];
    }
};