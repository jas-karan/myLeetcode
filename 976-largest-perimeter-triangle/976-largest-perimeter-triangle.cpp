class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=n-1;i>=2;i--){
            //nums[i-1] and nums[i-2] are two largest elements before nums[i]
            //if their sum exceeds nums[i] then any combo will make triangle with nums[i]
            if(nums[i]<nums[i-1]+nums[i-2]){
                return nums[i]+nums[i-1]+nums[i-2];
            }
        }
        return 0;
    }
};