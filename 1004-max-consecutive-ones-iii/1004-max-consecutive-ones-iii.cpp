class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int length=0;
        
        int l=0,r=0;
        int flipped=0;
        while(r<nums.size()){
            if(nums[r]==0) flipped++;
            
            while(l<=r && flipped>k){
                if(nums[l]==0) flipped--;
                l++;
            }
            
            length=max(length,r-l+1);
            r++;
        }
        
        return length;
    }
};