class Solution {
public:
    int dp[366];
    
    int dfs(vector<int>& days, vector<int>& costs,int d){
        int n=days.size();
        if(d==n) return 0;
        
        if(dp[d]!=-1) return dp[d];
        
        int ans=costs[0]+dfs(days,costs,d+1);
        
        int i;
        for(i=d;i<n&&days[i]<days[d]+7;i++);
        ans = min(ans,costs[1]+dfs(days,costs,i));
        
        for(i=d;i<n&&days[i]<days[d]+30;i++);
        ans = min(ans,costs[2]+dfs(days,costs,i));
       
        return dp[d]=ans;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return dfs(days,costs,0);
    }
};