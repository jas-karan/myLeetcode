class Solution {
public:
    int dp[100];
    int dfs(string s,int i){
        if(i>=s.length()) return 1;
        
        if(dp[i]!=-1) return dp[i];
        
        if(s[i]=='0') return dp[i]=0;
        
        int ans=dfs(s,i+1);
        if(i<s.length()-1){
            if(s[i]=='1') ans+=dfs(s,i+2);
            else if(s[i]=='2'&&s[i+1]<='6') ans+=dfs(s,i+2);
        }
        
        return dp[i]=ans;
    }
    
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return dfs(s,0);
    }
};