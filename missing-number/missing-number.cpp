class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_=n;
        
        for(int i=0;i<n;i++){
            xor_^=nums[i];
            xor_^=i;
        }
        
        return xor_;
    }
};