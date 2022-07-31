class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0;
        int maxSum = INT_MIN;
        
        for(int &i:nums){
            curr= max(curr+i,i);
            maxSum = max(maxSum, curr);
        }
        
        return maxSum;
    }
};