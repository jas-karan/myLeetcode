class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //we store the freq of sum in map
        
        unordered_map<int,int>freq;
        int sum = 0;
        int count = 0;
        
        for(int i:nums){
            sum+=i;
            
            if(sum==k) count++;
            if(freq.find(sum-k)!=freq.end()) count+=freq[sum-k];
            freq[sum]++;
        }
        
        return count;
    }
};