class Solution {
public:
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int rottenOranges=0;
        int oranges=0;
        int m = grid.size(), n=grid[0].size();
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    rottenOranges++;
                    oranges++;
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    oranges++;
                }
            }
        }
        
        int time = 2;
        while(q.size()){
            auto curr = q.front();
            int i = curr.first;
            int j = curr.second;
            q.pop();
            int t = grid[i][j];
            time = max(time,t);
            for(int d=0;d<4;d++){
                int x=i+dir[d][0];
                int y=j+dir[d][1];
                
                if(x>=0 && y>=0 && x<m && y<n && grid[x][y]==1){
                    grid[x][y]=1+t;
                    q.push({x,y});
                    rottenOranges++;
                }
            }
        }
        if(oranges!=rottenOranges) return -1;
        return time-2;
    }
};