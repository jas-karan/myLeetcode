class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int res = INT_MAX;
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int l=i+1,r=n-1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(sum==target){
                    return target;
                }
                else{
                    if(res==INT_MAX || abs(res-target)>abs(sum-target)) res = sum;
                    
                    if(sum>target) r--;
                    else l++;
                }
            }
        }
        
        return res;
    }
};