class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count = 0, sum = 0;
        
        for(int i = 0, j = 0; j < nums.size(); j++){
            int len = j - i + 1;
            sum += nums[j];
            
            while(sum * len >= k && i < j){
                sum -= nums[i++];
                len--;
            }
            
            if(sum * len < k) count += len;
        }
        
        return count;
    }
};