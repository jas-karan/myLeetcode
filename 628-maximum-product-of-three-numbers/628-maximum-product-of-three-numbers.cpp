class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        sort(begin(nums),end(nums));
        int n = nums.size();
        
        if(nums[n-1]<0) return nums[n-1]*nums[n-2]*nums[n-3];
        
        int product = nums[n-1]*nums[n-2]*nums[n-3];
        product = max(product, nums[n-1]*nums[0]*nums[1]);
        
        return product;
    }
};