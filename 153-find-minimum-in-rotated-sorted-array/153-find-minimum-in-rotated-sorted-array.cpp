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
        
        // l<h is used when we use arr[l] or arr[h]
        //l<=h is used when we want to return from loop
        
        while(l<h){
            int m=(l+h)/2;
            
            if(nums[m]>=nums[h]) l=m+1; //left is sorted
            else h=m;
        }
        
        return nums[l];
        
    }
};