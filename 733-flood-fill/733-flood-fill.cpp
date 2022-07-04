class Solution {
public:
    int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int m=grid.size(),n=grid[0].size();
        
        queue<pair<int,int>>q;
        q.push({sr,sc});
        bool vis[51][51]={false};
        
        while(!q.empty()){
            int sz=q.size();
            
            while(sz--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int x_=x+dir[i][0],y_=y+dir[i][1];
                    if(x_>=0 && y_>=0 && x_<m && y_<n && vis[x_][y_]==false && grid[x_][y_]==grid[x][y]){
                        q.push({x_,y_});
                        vis[x_][y_]=true;
                    }
                }
                
                grid[x][y]=color;
            }
        }
        
        return grid;
    }
};