class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // a+b+c+d = 0 then a+b = -(c+d)
        //we can store a+b in map then use that to find pairs c+d
        
        unordered_map<int,int>mp;
        int count = 0;
        for(int i:nums1){
            for(int j:nums2){
                mp[i+j]++;
            }
        }
        
        for(int i:nums3){
            for(int j:nums4){
                count+=mp[-(i+j)];
            }
        }
        
        return count;
        
        //we could have stored a+b+c or any other trio but that'd make O(n^3)
    }
};