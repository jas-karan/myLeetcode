class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        int l=0,h=n-1;
        int f = -1;
        while(l<=h){
            int m = (l+h)/2;
            if(nums[m]==target){
                f = m;
                h = m-1;
            }
            else if(nums[m]<target) l=m+1;
            else h=m-1;
        }
        
        int la = -1;
        l=0,h=n-1;
        while(l<=h){
            int m = (l+h)/2;
            if(nums[m]==target){
                la = m;
                l=m+1;
            }
            else if(nums[m]<target) l=m+1;
            else h=m-1;
        }
        
        return {f,la};
    }
};