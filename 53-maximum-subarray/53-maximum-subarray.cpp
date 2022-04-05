class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        int curr = 0;
        
        for(int n:nums){
            curr+=n;
            sum=max(curr,sum);
            if(curr<0) curr=0;
            //why ? - if curr sum is negative
            //if next number is negative then it will further decrease curr
            //so it is better that start next subarray from next element
            //if next is positive let curr = -2 and next element is 5
            //then -2+5 or 5 ,obviously 5 is better so start from next element new subarray
        }
        
        return sum;
    }
};