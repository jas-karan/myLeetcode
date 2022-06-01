class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>res(nums);
        for(int i=1;i<nums.size();i++){
            res[i]+=res[i-1];
        }
        return res;
    }
};