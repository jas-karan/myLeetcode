class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>sorted;
        sorted.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>sorted[sorted.size()-1]){   
                sorted.push_back(nums[i]);
            }
            else{
                int c = lower_bound(begin(sorted),end(sorted),nums[i])-begin(sorted);   
                sorted[c] = nums[i];
            }
        }
        
        return sorted.size();
    }
};