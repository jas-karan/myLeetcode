class Solution {
public:
    int jump(vector<int>& nums) {
        //dpi store the min jumps from i
        //from index j, you can go to j+1,j+2,...,j+nums[j] by one jump
        //from all these, find min dpj, and add 1 to it
        
        int n = nums.size();
        int dp[n];
        dp[n-1] = 0; //you are already at n-1
        
        for(int i=n-2;i>=0;i--){
            if(nums[i]==0){
                dp[i]=INT_MAX;
                continue;
            }
            
            dp[i] = INT_MAX;
            for(int j=i+1;j<n&&j<=i+nums[i];j++){
                dp[i]=min(dp[i],dp[j]);
            }
            if(dp[i]!=INT_MAX) dp[i]+=1;
        }
        
        return dp[0];
    }
};