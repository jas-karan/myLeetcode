class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        //same as LIS sum
        //sort by ages
        
        int n=scores.size();
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            v.push_back({ages[i],scores[i]});
        }
        
        sort(v.begin(),end(v));
        
        vector<int>dp(n);
        for(int i=0;i<n;i++){
            dp[i]=v[i][1];
            for(int j=i-1;j>=0;j--){
                if(v[j][1]<=v[i][1]){
                    dp[i]=max(dp[i],v[i][1]+dp[j]);
                }
                else if(v[j][0]==v[i][0]){
                    dp[i]=max(dp[i],v[i][1]+dp[j]);
                }
            }
        }
        
        int ans=1;
        for(int d:dp) ans=max(d,ans);
        return ans;
    }
};