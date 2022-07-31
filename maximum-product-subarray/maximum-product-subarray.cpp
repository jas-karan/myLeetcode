class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxP = nums[0], minP = nums[0]; 
        int cur = maxP;
        for(int i=1;i<n;i++){
            int maxEnd = max({nums[i], nums[i]*maxP, nums[i]*minP});
            minP = min({nums[i], nums[i]*minP, nums[i]*maxP});
            maxP = maxEnd;
            cur = max(cur, maxEnd);
        }
        
        return cur;
    }
};