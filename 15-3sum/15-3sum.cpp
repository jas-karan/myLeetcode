class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>triplets;
        int n = nums.size();
        
        sort(begin(nums),end(nums));
        
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            int l=i+1,h=n-1;
            int target = -nums[i];
            while(l<h){
                if(nums[l]+nums[h]==target){
                    triplets.push_back({nums[i],nums[l],nums[h]});
                    int l_=l,h_=h;
                    while(l<h && nums[l]==nums[l_]) l++;
                    while(l<h && nums[h]==nums[h_]) h--;
                }
                else if(nums[l]+nums[h]>target) h--;
                else l++;
            }
        }
        
        return triplets;
    }
};