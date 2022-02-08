class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        //dp[i] = maxlength subsequence considering nums[i] as last element
        
        int maxLength = 1;
        for(int i=0;i<n;i++){
            
            for(int j=i-1;j>=0;j--){
                
                if(nums[j]<nums[i]){ //if this number can be added to any sequence?
                    
                    dp[i]=max(dp[i],1+dp[j]);  //add 1 to length of that sequence
                }
            }
            maxLength = max(maxLength,dp[i]);
        }
        
        return maxLength;
    }
};