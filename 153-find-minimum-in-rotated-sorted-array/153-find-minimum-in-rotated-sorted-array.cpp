class Solution {
public:
    int findMin(vector<int>& nums) {
//         for(int i=1;i<nums.size();i++){
//             if(nums[i]<nums[i-1]) return nums[i];
//         }
        
//         return nums[0];  //array is not rotated
        
        //------ binary Search ----
        //finding pivot element - ele smaller than neighbors
        
        int n = nums.size();
        if(nums[0]<=nums[n-1]) return nums[0]; //if not rotated
        
        int l=0,h=n-1;
        while(l<=h){
            int m=(l+h)/2;
            
            //if arr is rotated, then m+1 always exist
            if(nums[m]>nums[m+1]) return nums[m+1];
            else if(nums[m]<nums[m-1]) return nums[m];
            else if(nums[m]>nums[0]) l=m+1;
            else h=m-1;
            
        }
        
        return nums[l];
        
    }
};