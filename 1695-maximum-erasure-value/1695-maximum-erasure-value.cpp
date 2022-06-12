class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>set;
        int sum = 0;
        int curr = 0;
        int l = 0;
        for(int r=0;r<nums.size();r++){
            curr += nums[r];
            while(set.find(nums[r])!=set.end()){
                curr -= nums[l];
                set.erase(nums[l]);
                l++;
            }
            set.insert(nums[r]);
            sum = max(sum,curr);
        }
        
        return sum;
    }
};