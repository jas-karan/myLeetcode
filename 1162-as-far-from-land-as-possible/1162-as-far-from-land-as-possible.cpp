class Solution {
public:
    //similar to zero-one matrix or rotten oranges
    //BFS, keep updating distances, initially put into queue 0 distance cells
    
    int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){  //land cell into queue and their closest land is zero
                    q.push({i,j});
                    grid[i][j]=0;
                }
                else grid[i][j]=-1; //unvisited water cell
            }
        }
        
        if(q.size()==0 || q.size()==n*n) return -1;
        
        int levels = -1;
        while(!q.empty()){
            int sz = q.size();
            levels++;
            while(sz--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
            
                for(int d=0;d<4;d++){
                    int i_ = i+dir[d][0];
                    int j_ = j+dir[d][1];
                
                    if(i_>=0 && j_>=0 && i_<n && j_<n && grid[i_][j_]==-1){
                        grid[i_][j_]=grid[i][j]+1;
                        q.push({i_,j_});
                    }
                }
            }
        }
        
        return levels;
    }
};