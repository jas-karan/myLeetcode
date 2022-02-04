class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //same as longest subarray with sum divisible by k
        //we store remainder freq;
        
        unordered_map<int,int>mp;
        int count=0;
        int sum=0,rem;
        
        for(int i:nums){
            sum+=i;
            rem=sum%k;
            if(rem<0) rem+=k;  //keep rem from 0 to k-1
            
            if(rem==0) count++;
            if(mp.find(rem)!=mp.end()) count+=mp[rem];
            mp[rem]++;
        }
        
        return count;
    }
};