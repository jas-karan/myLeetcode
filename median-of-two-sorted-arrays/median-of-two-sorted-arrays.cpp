class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if(m>n) return findMedianSortedArrays(nums2,nums1);
        
        int sz = m+n;
        
        int l=0,r=m;
        double ans;
        while(l<=r){
            int i = l+(r-l)/2;
            int j = (sz+1)/2-i;
            
            int a1 = (i==0)?INT_MIN:nums1[i-1];
            int b1 = (i==m)?INT_MAX:nums1[i];
            int a2 = (j==0)?INT_MIN:nums2[j-1];
            int b2 = (j==n)?INT_MAX:nums2[j];
            
            if(a1<=b2 && a2<=b1){
                if(sz&1) ans =  max(a1,a2);
                else{
                    ans = (double)(max(a1,a2)+min(b1,b2))/2;
                }
                break;
            }
            else if(a1>b2) r=i-1;
            else l=i+1;
        }
        
        return ans;
    }
};