class Solution {
public:
    int n;
    unordered_map<int,bool>memo;
    
    bool dfs(vector<int>&nums,int ind,int k,int curr,int tar,int mask){
        if(k==0) return true;
        
        if(curr>tar) return false;
        
        if(memo.count(mask)) return memo[mask];
        
        if(curr==tar){
            return memo[mask]=dfs(nums,0,k-1,0,tar,mask);
        }
        
        for(int j=ind;j<n;j++){
            if((mask&(1<<j))==0){
                mask = mask|(1<<j);
                
                if(dfs(nums,j+1,k,curr+nums[j],tar,mask)) return memo[mask]=true;
                
                mask = mask ^ (1<<j);
            }
        }
        return memo[mask]=false;
    }
    bool makesquare(vector<int>& nums) {
        int sum=0;
        n=nums.size();
        
        for(int i:nums) sum+=i;
        
        if(n<4||sum%4!=0) return false;
        
        return dfs(nums,0,4,0,sum/4,0);
    }
};