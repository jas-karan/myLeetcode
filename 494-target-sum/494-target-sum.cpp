class Solution {
public:
    int n,target;
    unordered_map<string,int>dp;
    
    int dfs(vector<int>&nums,int i,int sum){
        if(i==n){
            if(sum==target) return 1;
            return 0;
        }
        
        string s = to_string(i)+'#'+to_string(sum);
        
        if(dp.find(s)!=dp.end()) return dp[s];
        
        return dp[s]= dfs(nums,i+1,sum+nums[i])+dfs(nums,i+1,sum-nums[i]);
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        this->target=target;
        return dfs(nums,0,0);
    }
};