class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(begin(nums),end(nums));
        
        int n=nums.size();
        
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            int target = -nums[i];
            
            int j=i+1,k=n-1;
            while(j<k){
                if(nums[j]+nums[k]==target){
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1])j++;
                    while(j<k && k!=n-1 && nums[k]==nums[k+1]) k--;
                }
                else if(nums[j]+nums[k]>target) k--;
                else j++;
               
            }
        }
        
        return res;
    }
};