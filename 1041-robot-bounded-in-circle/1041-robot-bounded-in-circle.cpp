class Solution {
public:
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    bool isRobotBounded(string s) {
        int d = 0;
        int x = 0;
        int y = 0;
        for(int j=0;j<s.length();j++){
            if(s[j]=='G'){
                x+=dir[d][0];
                y+=dir[d][1];
            }
            else if(s[j]=='L') d=(d-1+4)%4;
            else d = (d+1)%4;
        }    
        
        return x==0&&y==0 || d!=0;
    }
};