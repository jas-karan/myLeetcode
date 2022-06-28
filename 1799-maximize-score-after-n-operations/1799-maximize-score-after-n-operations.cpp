class Solution {
public:
    int gcd[15][15];
    int memo[1<<14]={};
    int pairs,n;
    
    int dfs(vector<int>&nums,int p,int mask){
        if(p>pairs) return 0;
        
        if(memo[mask]!=0) return memo[mask];
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int tempMask = (1<<i)|(1<<j);
                if((mask&tempMask)==0)
                    memo[mask]=max(memo[mask], p*gcd[i][j]+dfs(nums,p+1,mask|tempMask));
            }
        }
        return memo[mask];
    }
    
    int maxScore(vector<int>& nums) {
        n=nums.size();
        pairs=n/2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) gcd[i][j]=__gcd(nums[i],nums[j]);
        }
        return dfs(nums,1,0);
    }
};