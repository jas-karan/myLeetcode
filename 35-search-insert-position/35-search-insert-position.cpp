class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0,r = nums.size()-1;
        int ind=nums.size();
        
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m]>=target){
                ind = m;
                r = m-1;
            }
            else l = m+1;
        }
        
        return ind;
    }
};