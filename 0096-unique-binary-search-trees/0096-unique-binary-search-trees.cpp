class Solution {
public:
    int numTrees(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        
        vector<int>dp(n+1,0);
        dp[0]=1,dp[1]=1,dp[2]=2;
        
        for(int i=3;i<=n;i++){
            int ans = 0;
            for(int j=0;j<i;j++){
                ans+=(dp[i-j-1]*dp[j]);
            }
            dp[i]=ans;
        }
        
        return dp[n];
    }
};