class Solution {
public:
//     int dp[1001];
    
//     int dfs(int i,vector<int>& cost){
//         if(i>=cost.size()) return 0;
//         if(dp[i]!=-1) return dp[i];
//         return dp[i]=cost[i]+min(dfs(i+1,cost),dfs(i+2,cost));
//     }
    
    int minCostClimbingStairs(vector<int>& cost) {
        // memset(dp,-1,sizeof(dp));
        // int ans1=dfs(0,cost);
        // int ans2=dfs(1,cost);
        // return min(ans1,ans2);
        
        // dp[0]=0;
        // dp[1]=0;
        int a=0,b=0;
        
        for(int i=2;i<=cost.size();i++){
            // dp[i] = min(cost[i-1]+dp[i-1], cost[i-2]+dp[i-2]);
            int c = min(cost[i-1]+b, cost[i-2]+a);
            a=b;b=c;
        }
        
        // return dp[cost.size()];
        return b;
    }
};