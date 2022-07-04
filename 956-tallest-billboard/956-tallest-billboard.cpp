class Solution {
public:
    int dp[21][5001];
    int n;
    
    int dfs(vector<int>&rods,int i,int s1,int s2){
        if(i>=n){
            if(s1==s2) return 0;
            return INT_MIN;
        }
        
        if(dp[i][abs(s1-s2)]!=-1) return dp[i][abs(s1-s2)];
        
        int t=dfs(rods,i+1,s1,s2);
        t = max(t,rods[i]+dfs(rods,i+1,s1+rods[i],s2));
        t = max(t,rods[i]+dfs(rods,i+1,s1,s2+rods[i]));
        
        return dp[i][abs(s1-s2)]=t;
    }
    
    int tallestBillboard(vector<int>& rods) {
        n=rods.size();
        memset(dp,-1,sizeof(dp));
        return dfs(rods,0,0,0)/2;
    }
};