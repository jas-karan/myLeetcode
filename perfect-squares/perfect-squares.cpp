class Solution {
public:
    int numSquares(int n) {
        //for every square of number <= n check if we include that square
        //then how many more squares we have to take ie dp[n-square]
        
        //dp[i] = perfect numbers required for n=i
        
        vector<int>dp(n+1,INT_MAX);
        
        dp[0]=0; //0 perfect numbers are req for n=0
        
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                
                dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
        
        return dp[n];
    }
};