class Solution {
public:
    
    int dfs(string s,int ind,vector<int>&dp,vector<vector<bool>>&mem){
        
        if(ind>=s.length()) return -1;
        if(dp[ind]!=-1) return dp[ind];
        int ans = INT_MAX;
        
        for(int i=ind;i<s.length();i++){
            if(s[i]==s[ind]&& (i-ind+1<=2 || mem[ind+1][i-1])){
                mem[ind][i]=true;
                ans=min(ans,1+dfs(s,i+1,dp,mem));
            }
        }
        
        return dp[ind]=ans;
    }
    
    int minCut(string s) {
        vector<vector<bool>>mem(s.length(),vector<bool>(s.length(),false));
        vector<int>dp(s.length(),-1);
        return dfs(s,0,dp,mem);
    }
};