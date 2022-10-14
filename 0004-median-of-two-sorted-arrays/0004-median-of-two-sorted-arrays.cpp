class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size()) return findMedianSortedArrays(nums2,nums1);
        int n=nums1.size();
        int m=nums2.size();
        int sz=m+n;
        int l=0,r=n;
        while(l<=r){
            int i = l+(r-l)/2;
            int j = ((sz+1)/2)-i;
            
            int l1 = i==0 ? INT_MIN : nums1[i-1];
            int l2 = j==0 ? INT_MIN : nums2[j-1];
            int r1 = i==n ? INT_MAX : nums1[i];
            int r2 = j==m ? INT_MAX : nums2[j];
            
            if(l1<=r2 && l2<=r1){
                if(sz%2==0){
                    return (double)(max(l1,l2)+min(r1,r2))/2.0;
                }
                else return max(l1,l2);
            }
            else if(l1>r2){
                r=i-1;
            }
            else l=i+1;
        }
        
        return 0.0;
    }
};