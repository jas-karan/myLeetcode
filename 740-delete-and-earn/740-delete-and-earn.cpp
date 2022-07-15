class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
      
        map<int,int>cnt;
        for(int i:nums){
            cnt[i]+=i;
        }
        
        nums.clear();
        for(auto e:cnt) nums.push_back(e.first); 
        int n = nums.size();
        vector<int>dp(n+1,0);
        dp[0]=0;
        dp[1]=cnt[nums[0]];
        
        for(int i=2;i<=n;i++){
            if(nums[i-1]==nums[i-2]+1){
                dp[i]=max(dp[i-1],cnt[nums[i-1]]+dp[i-2]);
            }
            else{
                dp[i]=dp[i-1]+cnt[nums[i-1]];
            }
        }
        
        return dp[n];
    }
};