
class Solution {
public:
    int atmost(vector<int>nums, int k){
        int count=0;
        
        int l=0,r=0;
        
        //no need of hashmap, we can simply count odds
        int odd=0;
        while(r<nums.size()){
            if(nums[r]%2) odd++;
            
            while(l<=r && odd>k){
                if(nums[l]%2) odd--;
                l++;
            }
            
            count+=(r-l+1);
            r++;
        }
        
        return count;
        
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count=0;
        
//         for(int i=k-1;i<n;i++){
//             int odd = 0;
//             for(int j=i;j>=0;j--){
//                 if(nums[j]%2!=0) odd++;
                
//                 if(odd==k) count++;
//                 else if(odd>k) break;
//             }
//         }
        
//         return count;
        
        //time limit exceeded
        
//-------replace even numbers with 0 and odd with 1 then it is same as finding
//subarrays with sum k
        
//         unordered_map<int,int>mp;
        
//         int sum = 0,count=0;
        
//         for(int i:nums){
//             if(i%2==1) sum++;
            
//             if(sum==k) count++;
//             if(mp.find(sum-k)!=mp.end()) count+=mp[sum-k];
//             mp[sum]++;
//         }
        
//         return count;
        
//-------------------important-----------------
        //finding exactly = k is atmost k minus atmost (k-1)
        return atmost(nums,k)-atmost(nums,k-1);
        
    }
};