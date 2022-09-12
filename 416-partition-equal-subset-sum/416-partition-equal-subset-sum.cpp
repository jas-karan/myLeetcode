class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i:nums){
            sum+=i;
        }
        
        if(sum%2!=0) return false;
        sum/=2;
        
        vector<vector<bool>>mem(n+1,vector<bool>(sum+1,false));
        
        for(int i=0;i<=n;i++) mem[i][0]=true;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1]<=j){
                    mem[i][j] = mem[i-1][j-nums[i-1]];
                }
                mem[i][j] = mem[i][j] || mem[i-1][j];
            }
        }
        
        return mem[n][sum];
    }
};