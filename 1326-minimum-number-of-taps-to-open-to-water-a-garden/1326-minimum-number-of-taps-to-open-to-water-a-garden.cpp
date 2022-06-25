class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jumps(n+1, 0);
        
        for(int i = 0; i<n+1; i++) {
            int l = max(0, i-ranges[i]);
            int r = min(n, i+ranges[i]);
            
            jumps[l] = max(jumps[l], r-l); //from l, that's farthest I can jump to right
        }
        
        //Now this questions has turned to Jump Game II
        
        vector<int>dp(n+1,INT_MAX);
        
        dp[n]=0;
        
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=jumps[i];j++){
                if(i+j>n) break;
                
                if(dp[j+i]!=INT_MAX) dp[i]= min(dp[i],1+dp[j+i]);
            }
        }
        
        return dp[0]==INT_MAX?-1:dp[0];
    }
};