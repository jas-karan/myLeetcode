class Solution {
public:
    int mp;
    int m;
    int dp[101][101][101];
    
    int dfs(int n,vector<int>&groups,vector<int>&profit,int i,int pro){
        if(n<0) return 0;
        
        if(i>=m){
            if(n>=0&&pro>=mp) return 1;
            return 0;
        }
        
        if(dp[i][n][pro]!=-1) return dp[i][n][pro];
        
        long ans = dfs(n-groups[i],groups,profit,i+1,min(pro+profit[i],mp));
        ans = (ans+dfs(n,groups,profit,i+1,pro))%1000000007;
        
        return dp[i][n][pro]=ans;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        mp=minProfit;
        m=profit.size();
        memset(dp,-1,sizeof(dp));
        return dfs(n,group,profit,0,0);
    }
};