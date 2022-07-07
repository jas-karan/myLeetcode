class Solution {
public:
    int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]!=0) return -1;
        
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            int dist = grid[x][y];
            if(x==n-1&&y==m-1){
                return dist;
            }
            
            for(int i=0;i<8;i++){
                int x_ = x+dir[i][0];
                int y_ = y+dir[i][1];
                
                if(x_<0 || y_<0 || x_>=n || y_>=m || grid[x_][y_]!=0) continue;
                
                grid[x_][y_]=dist+1;
                q.push({x_,y_});
                    
            }
        }
        
        return -1;
        
    }
};