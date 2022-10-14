class Solution {
public:
    void merge(vector<pair<int,int>>&nums,int l,int m,int r,vector<int>&cnt){
        vector<pair<int,int>>t(r-l+1);
        int i=l,j=m+1;
        int k=0;
        while(i<=m && j<=r){
            if(nums[i].first<=nums[j].first){
                t[k++] = nums[j++];
            }
            else{
                
                cnt[nums[i].second] += r-j+1;
                t[k++] = nums[i++];
            }
        }
        
        while(i<=m) t[k++] = nums[i++];
        while(j<=r) t[k++] = nums[j++];
        
        for(i=l;i<=r;i++){
            nums[i] = t[i-l];
        }
        
    }
    
    void mergeSort(vector<pair<int,int>>&nums,int l,int r,vector<int>&cnt){
        if(l>=r) return;
        
        int m = l+(r-l)/2;
        
        mergeSort(nums,l,m,cnt);
        mergeSort(nums,m+1,r,cnt);
        merge(nums,l,m,r,cnt);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>cnt(nums.size(),0);
        vector<pair<int,int>>num(nums.size());
        
        for(int i=0;i<nums.size();i++){
            num[i] = {nums[i],i};
        }
        
        mergeSort(num,0,nums.size()-1,cnt);
        return cnt;
    }
};