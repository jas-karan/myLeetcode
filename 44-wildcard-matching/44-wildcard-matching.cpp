class Solution {
public:
    bool isMatch(string s, string p) {
        int a = s.length();
        int b = p.length();
        
        vector<vector<bool>>mem(a+1,vector<bool>(b+1,false));
        
        mem[0][0] = true;
        
        for(int j=1;j<=b;j++){
            mem[0][j] = ((p[j-1]=='*') && mem[0][j-1]);
        }
        
        
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    mem[i][j] = mem[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    mem[i][j] = mem[i-1][j] || mem[i][j-1];
                }
            }
        }
        
        return mem[a][b];
    }
};