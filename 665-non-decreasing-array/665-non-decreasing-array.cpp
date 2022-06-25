class Solution {
public:
    bool check(vector<int>& nums){
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]) return false;
        }
        
        return true;
    }
    
    bool checkPossibility(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                int t = nums[i];
                nums[i] = nums[i+1];
                bool p = check(nums);
                nums[i+1]=t;
                nums[i]=t;
                p|=check(nums);
                return p;
            }
        }
        
        return true;
    }
};