class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        
        while(i>=0 && nums[i+1]<=nums[i]){  //find decreasing element
            i--;
        }
        
        if(i>=0){
            int j = nums.size()-1;
            while(nums[j]<=nums[i]) j--;  //number just greater than nums[i]
            swap(nums[i],nums[j]);
        }
        
        reverse(nums.begin()+i+1,nums.end());
    }
};