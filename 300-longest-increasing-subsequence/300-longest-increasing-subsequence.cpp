class Solution {
public:
    int ceil(vector<int>sorted,int x){
        int index;
        int l=0,r=sorted.size()-1;
        
        while(l<=r){
            int mid = l+(r-l)/2;
            
            if(sorted[mid]<x) l=mid+1;
            else{
                index=mid;
                r=mid-1;
            }
        }
        
        return index;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
//         vector<int>dp(n,1);
//         //dp[i] = maxlength subsequence considering nums[i] as last element
        
//         int maxLength = 1;
//         for(int i=0;i<n;i++){
            
//             for(int j=i-1;j>=0;j--){
                
//                 if(nums[j]<nums[i]){ //if this number can be added to any sequence?
                    
//                     dp[i]=max(dp[i],1+dp[j]);  //add 1 to length of that sequence
//                 }
//             }
//             maxLength = max(maxLength,dp[i]);
//         }
        
//         return maxLength;
        
        vector<int>sorted;
        sorted.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>sorted[sorted.size()-1]){
                sorted.push_back(nums[i]);
            }
            else{
                int c = ceil(sorted,nums[i]);
                sorted[c] = nums[i];
            }
        }
        
        return sorted.size();
    }
};