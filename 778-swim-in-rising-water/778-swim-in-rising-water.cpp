class Solution {
public:
    int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        //basically from all the paths possible, select min you have to wait for
        //for a path, wait time is max cell value of that path
        
        //finding shortest path to target - djikstra algorithm
        //djikstra and prims are almost same - both use priority queue to get min edge 
        //0-1 bfs is special case of djikstra- only two edges 0 and 1 weight
        
        //instead of node value as path sum as in djikstra, here
        //node value is highest value cell till that node
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; //min heap (node val)
        pq.push({grid[0][0],0,0}); //source should be selected first
        
        vector<vector<bool>>vis(n,vector<bool>(n,0));
        
        while(!pq.empty()){
            int i = pq.top()[1];
            int j = pq.top()[2];
            int wt = pq.top()[0];
            pq.pop();
            
            if(i==n-1 && j==n-1) return wt;  //if we reached target
            
            if(vis[i][j]==true) continue;
            
            vis[i][j]=true;
            
            for(int d=0;d<4;d++){
                int i_ = i+dir[d][0];
                int j_ = j+dir[d][1];
                
                if(i_>=0 && j_>=0 && i_<n && j_<n && !vis[i_][j_]){
                    pq.push({max(wt,grid[i_][j_]),i_,j_});
                }
            }
        }
        
        return -1;
    }
};