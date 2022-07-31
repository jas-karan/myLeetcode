class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(target<nums[0]) return 0;
        if(target>nums[n-1]) return n;
        
        int l=0,r=n-1;
        
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m]==target) return m;
            if(nums[m]>target && nums[m-1]<target) return m;
            if(nums[m]<target && nums[m+1]>target) return m+1;
            if(nums[m]>target) r=m-1;
            else l=m+1;
        }
        
        return l;
    }
};