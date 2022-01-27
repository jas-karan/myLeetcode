class Solution {
public:
    bool possible(vector<int>nums, int div, int t){
        int sum = 0;
        for(int n : nums){
            sum+=(ceil((n*1.0)/div));
        }
        
        return sum<=t;
    }
    
    int smallestDivisor(vector<int>& nums, int t) {
        int l=1,h=INT_MIN;
        for(int n:nums) h=max(h,n);
        
        int divisor;
        
        while(l<=h){
            int m = l+(h-l)/2;
            
            if(possible(nums,m,t)){
                divisor = m;
                h = m-1;
            }
            else l= m+1;
        }
        
        return divisor;
    }
};