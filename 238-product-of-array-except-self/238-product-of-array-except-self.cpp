class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n);
        
        int curr=1;
        for(int i=0;i<n;i++){
            res[i]=curr;
            curr*=nums[i];
        }
        curr=1;
        for(int i=n-1;i>=0;i--){
            res[i]*=curr;
            curr*=nums[i];
        }
        
        return res;
    }
};