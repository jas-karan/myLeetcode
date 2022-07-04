class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n =nums1.size();
        
        vector<int>keep(n,0);
        vector<int>swap(n,0);
        swap[0]=1;
        
        for(int i=1;i<n;i++){
            if(nums1[i]>nums1[i-1]&&nums1[i]>nums2[i-1]&&nums2[i]>nums2[i-1]&&nums2[i]>nums1[i-1]){
                keep[i] = min(keep[i-1],swap[i-1]);
                swap[i] = min(swap[i-1],keep[i-1])+1;
            }
            else if(nums1[i]>nums1[i-1]&&nums2[i]>nums2[i-1]){
                keep[i]=keep[i-1];
                swap[i]=swap[i-1]+1;
            }
            else{
                keep[i]=swap[i-1];
                swap[i]=keep[i-1]+1;
            }
        }
        
        return min(swap[n-1],keep[n-1]);
    }
};