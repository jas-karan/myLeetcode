class Solution {
public:
    unordered_map<int,int>ind;
    
    bool dfs(int lastjump, int curr, vector<vector<int>>&dp, int reqd){
        if(curr==reqd) return true;
        
        if(dp[ind[curr]][lastjump]!=-1) return dp[ind[curr]][lastjump];
        
        bool t=false;
        for(int i=lastjump-1;i<=lastjump+1;i++){
            if(curr+i!=curr && ind.find(curr+i)!=ind.end()){
                t = t|| dfs(i,curr+i,dp,reqd);
            }
        }
        
        return dp[ind[curr]][lastjump]=t;
    }
    
    bool canCross(vector<int>& s) {
        int n=s.size();
        if(n>=2 && s[1]!=1) return false;
        if(n<=2) return true;
        
        for(int i=0;i<n;i++) ind[s[i]]=i;
        //using map to store indices 
        //indices reqd for dp array
        
        vector<vector<int>> dp(n,vector<int>(1000,-1));
        return dfs(1,1,dp,s[n-1]);
    }
};