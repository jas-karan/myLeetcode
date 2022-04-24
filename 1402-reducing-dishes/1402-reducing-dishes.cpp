class Solution {
public:
    int call(int i,int t,vector<int>&sat,vector<vector<int>>&dp){
        if(i==sat.size()) return 0;
        if(dp[i][t]!=-1) return dp[i][t];
        
        int a = (t*sat[i])+call(i+1,t+1,sat,dp);
        int b = call(i+1,t,sat,dp);
        
        dp[i][t] = max(a,b);
        
        return dp[i][t];
    }
    
    int maxSatisfaction(vector<int>& sat) {
        int n=sat.size();
        sort(sat.begin(),sat.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        return call(0,1,sat,dp);
    }
};