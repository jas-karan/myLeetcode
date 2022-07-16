class Solution {
public:
    unordered_map<char,vector<char>>map;
    
    int dfs(int n,char prev,vector<vector<int>>&dp){
        if(n==0) return 1;
        
        if(dp[n][prev-'a']!=-1) return dp[n][prev-'a'];
        
        int ans=0;
        
        for(auto c:map[prev]){
            ans=(ans+dfs(n-1,c,dp))%1000000007;
        }
        
        return dp[n][prev-'a']=ans;
    }
    
    int countVowelPermutation(int n) {
        vector<vector<int>>dp(n+1,vector<int>(26,-1));
        map['a']={'e'};
        map['e']={'a','i'};
        map['i']={'a','e','o','u'};
        map['o']={'i','u'};
        map['u']={'a'};
        map['x']={'a','i','o','u','e'};
        
        return dfs(n,'x',dp);
    }
};