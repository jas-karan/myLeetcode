class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int length=0;
        
        int ones = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]) ones++;
            
            else{
                length=max(length,ones);
                ones=0;
            }
        }
        
        return max(length,ones);
    }
};