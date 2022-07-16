class Solution {
public:
    int n;
    vector<int>diff;
    vector<vector<int>>dp;
    int d;
    vector<int>hardest;
    
    
    int dfs(int i,int day){
        if(day==d) return hardest[i];
        
        if(dp[i][day]!=-1) return dp[i][day];
        
        int hard=INT_MIN;
        int best=INT_MAX;
        for(int j=i;j<(n-(d-day));j++){
            hard=max(hard,diff[j]);
            best = min(best, hard+dfs(j+1,day+1));
        }
        
        return dp[i][day]=best;
    }
    
    int minDifficulty(vector<int>& diff, int d) {
        n = diff.size();
        this->d=d;
        if(n<d) return -1;
        
        this->diff=diff;
        dp=vector<vector<int>>(n,vector<int>(d+1,-1));
        hardest=vector<int>(n);
        
        int hard=INT_MIN;
        for(int i=n-1;i>=0;i--){
            hard=max(hard,diff[i]);
            hardest[i]=hard;
        }
        
        return dfs(0,1);
    }
};