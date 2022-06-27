class Solution {
public:
    vector<vector<int>>dir{{0,1},{-1,0},{0,-1},{1,0}};
    
    bool isRobotBounded(string instructions) {
        int x=0,y=0,d=0;
        
        instructions+=instructions+instructions+instructions;
        
        for(char c:instructions){
            if(c=='L') d=(d-1+4)%4;
            else if(c=='R') d=(d+1)%4;
            else{
                x+=dir[d][0];
                y+=dir[d][1];
            }
            
        }
        
        if(x==0&&y==0) return true;
        return false;
    }
};