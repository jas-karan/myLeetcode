class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        int down=1,up=1;
        
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                up=down+1;
            }
            if(nums[i]<nums[i-1]){
                down=up+1;
            }
        }
        
        return max(up,down);
    }
};