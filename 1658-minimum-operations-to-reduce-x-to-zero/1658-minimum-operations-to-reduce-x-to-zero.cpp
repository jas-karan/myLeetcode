class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(int i:nums) sum+=i;
        
        sum-=x;
        //find longest subarray with this sum
        if(sum==0) return nums.size();
        if(sum<0) return -1;
        
        unordered_map<int,int>map;
        
        int curr = 0;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            if(curr==sum) ans=i+1;
            else if(map.find(curr-sum)!=map.end()){
                ans = max(ans,i-map[curr-sum]);
            }
            
            map[curr]=i;
        }
        
        if(ans==-1) return -1;
        
        return nums.size()-ans;
        
    }
};