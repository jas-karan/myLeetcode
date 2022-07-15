class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int n = nums.size();
        int m = mul.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,0));
        
        for(int i=m-1;i>=0;i--){
            for(int l=i;l>=0;l--){
                int r=n-1-(i-l);
                dp[i][l]=max(mul[i]*nums[l]+dp[i+1][l+1],mul[i]*nums[r]+dp[i+1][l]);
            }
        }
        
        return dp[0][0];
    }
};