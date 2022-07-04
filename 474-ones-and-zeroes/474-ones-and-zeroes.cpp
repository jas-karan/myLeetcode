class Solution {
public:
    int dp[601][101][101];
    
    int dfs(int i,int m,int n,vector<string>&strs){
        if(i>=strs.size()) return 0;
        
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        
        int a=0,b=0;
        for(char c:strs[i]){if(c=='0') a++; else b++;}
        
        int ans=-1;
        if(a<=m&&b<=n) ans=1+dfs(i+1,m-a,n-b,strs);
        
        return dp[i][m][n] = max(ans,dfs(i+1,m,n,strs));
        
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return dfs(0,m,n,strs);
    }
};