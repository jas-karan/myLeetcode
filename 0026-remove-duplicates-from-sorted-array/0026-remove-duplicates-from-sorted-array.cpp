class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        int l = 1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[l-1]) continue;
            swap(nums[i],nums[l]);
            l++;
        }
        return l;
    }
};