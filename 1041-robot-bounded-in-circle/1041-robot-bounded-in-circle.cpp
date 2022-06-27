class Solution {
public:
    vector<vector<int>>dir{{0,1},{0,-1},{-1,0},{1,0}};
    
    int left(int d){
        if (d == 0) return 2;
        if (d == 2) return 1;
        if (d == 1) return 3;
        return 0;
    }
    
    int right(int d){
        if (d == 0) return 3;
        if (d == 3) return 1;
        if (d == 1) return 2;
        return 0;
    }
    
    bool isRobotBounded(string instructions) {
        int x=0,y=0,d=0;
        
        instructions+=instructions+instructions+instructions;
        
        for(char c:instructions){
            if(c=='L') d=left(d);
            else if(c=='R') d=right(d);
            else{
                x+=dir[d][0];
                y+=dir[d][1];
            }
            
        }
        
        if(x==0&&y==0) return true;
        return false;
    }
};