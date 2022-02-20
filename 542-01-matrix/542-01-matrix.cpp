class Solution {
public:
    const vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    
//     int bfs(vector<vector<int>>mat,int i,int j){
        
//         queue<pair<pair<int,int>,int>>q;
//         q.push({{i,j},1});
        
//         while(!q.empty()){
            
//             pair<int,int>curr = q.front().first;
//             int dist = q.front().second;
//             q.pop();
//             for(int d=0;d<4;d++){
//                 int i_ = curr.first+dir[d][0];
//                 int j_ = curr.second+dir[d][1];
                
//                 if(i_>=0 && i_<mat.size() && j_>=0 && j_<mat[0].size()){
//                     if(mat[i_][j_]==0) return dist;
//                     else q.push({{i_,j_},dist+1});
//                 }
//             }
//         }
        
//         return -1;
//     }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //intiution - BFS
        //from every 1 cell, do bfs
        //bfs is level order traversal ie cells at dist 1 will be visited first and so on..
        //at any level if I find any 0, that level will be the nearest zero dist
        
        // for(int i=0;i<mat.size();i++){
        //     for(int j=0;j<mat[0].size();j++){
        //         if(mat[i][j]==1){
        //             mat[i][j]=bfs(mat,i,j);
        //         }
        //     }
        // }
        //above  = TLE O(n^2 * m^2)
        
        
        //improved BFS ----------
        //store 0's in queue and mark 1's unvisited (-1)
        
        //keep poping cords from queue and see if they can update any unvisited 4 direc cords
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]) mat[i][j]*=-1;
                else q.push({i,j});
            }
        }
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(int d=0;d<4;d++){
                int i_ = i+dir[d][0];
                int j_ = j+dir[d][1];
                
                if(i_>=0 && i_<mat.size() && j_>=0 && j_<mat[0].size() && mat[i_][j_]<0){
                    mat[i_][j_]=mat[i][j]+1;
                    q.push({i_,j_});
                }
                
            }
        }
        
        
        return mat;
    }
};