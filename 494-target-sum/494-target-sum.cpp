class Solution {
public:
    int n,target,ans=0;
    
    void dfs(vector<int>&nums,int i,int sum){
        if(i==n){
            if(sum==target) ans++;
            return;
        }
        
        dfs(nums,i+1,sum+nums[i]);
        dfs(nums,i+1,sum-nums[i]);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        this->target=target;
        dfs(nums,0,0);
        return ans;
    }
};