class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int i = n-2;
        while(i>=0){
            if(nums[i]<nums[i+1]) break;
            i--;
        }
        
        if(i<0){
           reverse(begin(nums), end(nums));
            return;
        }
        
        int j = n-1;
        while(nums[j]<=nums[i]) j--;
        
        swap(nums[i],nums[j]);
        
        reverse(begin(nums)+i+1,end(nums));
        return ;
    }
};