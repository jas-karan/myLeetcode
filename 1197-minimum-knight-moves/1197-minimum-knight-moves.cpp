class Solution {
public:
    int dir[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2},{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
    
    int minKnightMoves(int i, int j) {
        
        bool vis[607][607]={false};
        queue<pair<int,int>>q;
        
        q.push({0,0});
        vis[302][302]=true;
        
        int steps=0;
        
        while(q.size()){
            int sz=q.size();
            
            while(sz--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                
                if(x==i&&y==j) return steps;
                
                for(int i=0;i<8;i++){
                    int x_ = x+dir[i][0];
                    int y_ = y+dir[i][1];
                    
                    if(vis[x_+302][y_+302]==false){
                        vis[x_+302][y_+302]=true;
                        q.push({x_,y_});
                    }
                }
            }
            
            steps++;
        }
        
        return steps;
    }
};