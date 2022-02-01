class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //convert all 0's to -1's then 
        //just find largest zero sum subarray
        
        int length=0;
        int sum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]==0)?-1:1;
            if(sum==0) length=i+1;
            if(mp.find(sum)!=mp.end()) length=max(length,i-mp[sum]);
            if(mp.find(sum)==mp.end()) mp[sum]=i;
        }
        
        return length;
    }
};