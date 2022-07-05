class Solution {
public:
//     int dfs(int txnleft,vector<int>prices,int ind,vector<vector<int>>&memo){
//         if(txnleft==0 || ind>=prices.size()) return 0;
        
//         if(memo[ind][txnleft]!=-1) return memo[ind][txnleft];
        
//         int ans1=dfs(txnleft,prices,ind+1,memo);
        
//         bool buy=false;
//         if(txnleft%2==0) buy=true;
        
//         int ans2;
//         if(buy) ans2=-prices[ind]+dfs(txnleft-1,prices,ind+1,memo);
//         else ans2=prices[ind]+dfs(txnleft-1,prices,ind+1,memo);
        
//         return memo[ind][txnleft] = max(ans1,ans2);
//     }
    
    int maxProfit(vector<int>& prices) {
//         int k=2;
//         int txnleft=2*k;
        
//         vector<vector<int>> memo(prices.size(), vector<int>(5, -1));
        
//         return dfs(txnleft,prices,0,memo);
        
        int n=prices.size();
        int k=2;
        int txns=k*2;
        
        vector<vector<int>>dp(n+1,vector<int>(txns+1));
        
        for(int i=n;i>=0;i--){
            for(int j=0;j<=txns;j++){
                
                if(i==n) dp[i][j]=0;
                else if(j==0) dp[i][j]=0;
                else{
                    int ans1=dp[i+1][j];  //no txn 
                    int ans2;
                    bool buy_day = j%2==0 ? true:false;
                    if(buy_day) ans2=-prices[i]+dp[i+1][j-1];
                    else ans2=prices[i]+dp[i+1][j-1];
                    
                    dp[i][j]=max(ans1,ans2);
                }
            }
        }
        
        return dp[0][txns];
    
    }
};