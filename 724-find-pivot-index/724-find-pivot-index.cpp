class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
//         int pre[n], suf[n];
        
//         pre[0] = 0; suf[n-1] = 0;
        
//         for(int i=1;i<n;i++) pre[i]=pre[i-1]+nums[i-1]; //left element + left of left element
//         for(int i=n-2;i>=0;i--) suf[i]=suf[i+1]+nums[i+1]; 
        
//         for(int i=0;i<n;i++) if(pre[i]==suf[i]) return i;
        
//         return -1;
        
        int lsum = 0, rsum = 0;
        
        for(int i=n-1;i>0;i--) rsum+=nums[i]; // for first element
        
        for(int i=0;i<n;i++){
            if(lsum == rsum) return i;
            lsum+=nums[i];
            if(i<n-1)rsum-=nums[i+1];
            else rsum=0;   //make it zero for last element
        }
        
        return -1;
    }
};