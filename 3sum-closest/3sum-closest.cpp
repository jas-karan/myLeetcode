class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = INT_MIN;
        int n = nums.size();
        
        sort(begin(nums),end(nums));
        
        for(int i=0;i<n;i++){
            int l=i+1,r=n-1;
            while(l<r){
                int cur = nums[i]+nums[l]+nums[r];
                if(ans==INT_MIN || abs(ans-target)>abs(cur-target)) ans=cur;
                
                if(cur==target) return target;
                if(cur<target) l++;
                else r--;
            }
        }
        
        return ans;
    }
};