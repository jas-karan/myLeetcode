class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // for n identical elements, nC2 pairs are possible
        
        //so we count occurence of each element and then add apirs possible
        
        vector<int>mp(101,0);
        for(int i:nums) mp[i]++;
        
        int pairs = 0;
        for(int i:mp) pairs+=(i*(i-1))/2;
        
        return pairs;
    }
};