class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        buildHeap(nums);
        
        for(int i=1;i<k;i++){
            swap(nums[0],nums[nums.size()-1]);
            nums.pop_back();
            heapify(nums,0);
        }
        
        return nums[0];
    }
    
    void heapify(vector<int>&nums, int ind){
        int l = ind*2+1, r = ind*2+2;
        
        int t=ind;
        if(l<nums.size() && nums[l]>nums[t]) t=l;
        if(r<nums.size() && nums[r]>nums[t]) t=r;
        
        if(t!=ind){ swap(nums[ind],nums[t]); heapify(nums,t);}
        
        
    }
    
    void buildHeap(vector<int>&nums){
        for(int i=(nums.size()/2)-1;i>=0;i--) heapify(nums,i);
    }
};