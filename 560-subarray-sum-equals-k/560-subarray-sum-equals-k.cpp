class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int sum=0;
        unordered_map<int,int>sum_count;
        
        for(int x:nums){
            sum += x;
            if(sum==k) count++;
            if(sum_count.find(sum-k)!=sum_count.end()) count+=sum_count[sum-k];
            sum_count[sum]++;
        }
        
        return count;
    }
};