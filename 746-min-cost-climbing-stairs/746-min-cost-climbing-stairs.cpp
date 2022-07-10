class Solution {
public:
    int dp[1000];
    
    int dfs(int i,vector<int>& cost){
        if(i>=cost.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i]+min(dfs(i+1,cost),dfs(i+2,cost));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int ans1=dfs(0,cost);
        int ans2=dfs(1,cost);
        return min(ans1,ans2);
    }
};