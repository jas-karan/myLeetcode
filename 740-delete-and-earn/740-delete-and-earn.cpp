class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxn=0;
        unordered_map<int,int>cnt;
        for(int i:nums){
            cnt[i]+=i;
            maxn=max(maxn,i);
        }
        
        vector<int>dp(maxn+1,0);
        dp[0]=0;
        dp[1]=cnt[1];
        
        for(int i=2;i<=maxn;i++){
            dp[i]=max(dp[i-1],cnt[i]+dp[i-2]);
        }
        
        return dp[maxn];
    }
};