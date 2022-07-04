class Solution {
public:
    int dp[5001][4][4][4];
    
    long dfs(int n,int a0,int b0,int c0){
        if(n==0) return 1;
        
        if(dp[n][a0][b0][c0]!=-1) return dp[n][a0][b0][c0];
        
        int colors[]={1,2,3};
        long ans=0;
        
        for(int a:colors){
            if(a==a0) continue;
            
            for(int b:colors){
                if(b==b0 || b==a) continue;
                
                for(int c:colors){
                    if(c==c0 || c==b) continue;
                    
                    ans = (ans+dfs(n-1,a,b,c))%1000000007;
                }
            }
        }
        
        return dp[n][a0][b0][c0]=ans;
    }
    
    int numOfWays(int n) {
        memset(dp,-1,sizeof(dp));
        
        return dfs(n,0,0,0);
    }
};