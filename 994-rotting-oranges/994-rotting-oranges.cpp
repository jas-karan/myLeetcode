class Solution {
public:
    //same as zero one matrix - ie, find closest zero to each one
    
    int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        int oranges = 0;
        queue<pair<int,int>>q;
        
        //store rotten oranges to queue
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    oranges++;
                }
                else if(grid[i][j]==2) q.push({i,j});
            }
        }
        
        int time = 2;
        int contaminated = 0;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(int d=0;d<4;d++){
                int i_ = i+dir[d][0];
                int j_ = j+dir[d][1];
                
                if(i_>=0 && j_>=0 && i_<m && j_<n && grid[i_][j_]==1){
                    grid[i_][j_]=grid[i][j]+1;
                    q.push({i_,j_});
                    contaminated++;
                    time = max(time,grid[i_][j_]);
                }
            }
        }
        
        if(contaminated!=oranges) return -1;
        
        return time-2;
    }
};