class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        int curr = 0;
        
        for(int n:nums){
            curr+=n;
            sum=max(curr,sum);
            if(curr<0) curr=0;
        }
        
        return sum;
    }
};