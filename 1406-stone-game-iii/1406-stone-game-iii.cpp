class Solution {
public:
    vector<int>dp;
    
    int dfs(int ind,vector<int>&val){
        if(ind>=val.size()) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        dp[ind] = val[ind]-dfs(ind+1,val);
        if(ind+1<val.size()) dp[ind]=max(dp[ind],val[ind]+val[ind+1]-dfs(ind+2,val));
        if(ind+2<val.size()) dp[ind]=max(dp[ind],val[ind]+val[ind+1]+val[ind+2]-dfs(ind+3,val));
        
        return dp[ind];
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        dp = vector<int>(stoneValue.size(),-1);
        int alice = dfs(0,stoneValue);
        if(alice>0) return "Alice";
        if(alice<0) return "Bob";
        return "Tie";
    }
};