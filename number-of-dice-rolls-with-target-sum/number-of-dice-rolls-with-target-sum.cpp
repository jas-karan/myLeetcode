class Solution {
public:
    int dp[31][1001];
    
    int dfs(int n,int k,int target){
        if(n==0){
            if(target==0) return 1;
            return 0;
        }
        
        if(dp[n][target]!=-1) return dp[n][target];
        
        int ans=0;
        for(int i=1;i<=k;i++){
            if(i<=target)
                ans = (ans+dfs(n-1,k,target-i))%1000000007;
        }
        
        return dp[n][target]=ans;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return dfs(n,k,target);
    }
};