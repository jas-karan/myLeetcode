class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
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