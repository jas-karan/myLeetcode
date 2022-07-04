class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        
        vector<int>dp(n+1,0),dp1(n+1,0);
        dp[1]=nums[0];
        
        for(int i=2;i<n;i++){
            dp[i] = max(nums[i-1]+dp[i-2], dp[i-1]);
        }
        for(int i=2;i<=n;i++){
            dp1[i] = max(nums[i-1]+dp1[i-2], dp1[i-1]);
        }
        
        return max(dp[n-1],dp1[n]);
        
    }
};