class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>s;
        for(int i=0;i<nums.size();i++){
            if(s.find(target-nums[i])!=s.end()) return {i,s[target-nums[i]]};
            else s.insert({nums[i],i});
        }
        return {-1,-1};
    }
};