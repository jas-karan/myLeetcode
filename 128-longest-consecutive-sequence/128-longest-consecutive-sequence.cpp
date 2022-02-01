class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set;
        for(int x:nums) set.insert(x);
        
        int length=0;
        
        for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            //if the current number is starting point
            if(set.find(curr-1)==set.end()){
                int count=1;
                while(set.find(++curr)!=set.end()){
                    count++;
                }
                length=max(length,count);
            }
        }
        
        return length;
    }
};