class Solution {
public:
    int res=0;
    
    bool safe(vector<string>conf,int r,int c,int n){
        for(int i=0;i<r;i++){
            if(conf[i][c]=='Q') return false;
        }
        for(int i=r,j=c;i>=0&&j>=0;i--,j--){
            if(conf[i][j]=='Q') return false;
        }
        for(int i=r,j=c;i>=0&&j<n;i--,j++){
            if(conf[i][j]=='Q') return false;
        }
        
        return true;
    }
    
    void dfs(vector<string>conf,int r,int n){
        if(r==n){
            res++;
            return;
        }
        
        for(int c=0;c<n;c++){
            if(safe(conf,r,c,n)){
                conf[r][c] = 'Q';
                dfs(conf,r+1,n);
                conf[r][c] = '.';
            }
        }
        
        return;
    }
    
    int totalNQueens(int n) {
        string s="";
        for(int i=0;i<n;i++) s+='.';
        
        vector<string>conf(n,s);
        
        dfs(conf,0,n);
        
        return res;
    }
};