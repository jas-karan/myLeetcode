class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(int i:nums) sum+=i;
        
        sum-=x;
        //find longest subarray with this sum
        if(sum==0) return nums.size();
        if(sum<0) return -1;
        
       
        int curr = 0;
        int ans=-1;
        int l=0;
        for(int r=0;r<nums.size();r++){
            curr+=nums[r];
            while(curr>sum){
                curr-=nums[l];
                l++;
            }
            if(curr==sum){
                ans=max(ans,r-l+1);
            }
        }
        
        if(ans==-1) return -1;
        
        return nums.size()-ans;
        
    }
};