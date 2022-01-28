// --------- same as allocate minimum number of pages ---------------------------

class Solution {
public:
    bool possible(vector<int>arr, int m, int max_sum){
        int subarrays = 1;
        int curr_sum = 0;
        
        for(int i:arr){
            curr_sum+=i;
            if(curr_sum>max_sum){
                subarrays++;
                curr_sum=i;
            }
        }
        
        return subarrays<=m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        
        int l=INT_MIN,h=0;
        for(int i:nums){
            l =  max(l,i);
            h += i;
        }
        
        int max_sum;
        while(l<=h){
            int mid = l+(h-l)/2;
            
            //if this max sum is possible
            if(possible(nums,m,mid)){
                max_sum = mid;
                h = mid-1;
            }
            else l = mid+1;
        }
        
        return max_sum;
    }
};