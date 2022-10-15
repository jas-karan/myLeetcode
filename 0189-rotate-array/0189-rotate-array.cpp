class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        if(k==0) return ;
        
        reverse(begin(nums),begin(nums)+n-k);
        reverse(begin(nums),end(nums));
        reverse(begin(nums),begin(nums)+k);
        
        return ;
        
    }
};