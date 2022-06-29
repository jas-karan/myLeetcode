class Solution {
public:
    int rearrangeSticks(int n, int k) {
        //out of k sticks, while putting ith stick 
        //assume that larger sticks than i are already arranged
        //putting ith stick such that j sticks are visible
        //dp[i][j] = dp[i-1][j-1] + dp[i-1][j]*(i-1)
        //put ith stick to front ->it will be visible
        //put ith stick somewhere in (i-1) positions
        
        vector<vector<long>>dp(n+1,vector<long>(k+1,0));
        
        dp[1][1]=1;
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=min(i,k);j++){
                dp[i][j] = dp[i-1][j-1];
                dp[i][j] += (dp[i-1][j])*(i-1);
                dp[i][j]%=1000000007;
            }
        }
        
        return dp[n][k];
    }
};