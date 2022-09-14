class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int i=1,j=1;
        vector<long long>sum1(m+1,0),sum2(n+1,0);
        
        while(i<=m || j<=n){
            if(i<=m && j<=n && nums1[i-1]==nums2[j-1]){
                sum1[i]=sum2[j] = max(sum1[i-1],sum2[j-1])+nums1[i-1]; 
                i++;j++;
            }
            else if(i<=m && (j>n || nums1[i-1]<nums2[j-1])){
                sum1[i]=sum1[i-1]+nums1[i-1];
                i++;
            }
            else{
                sum2[j]=sum2[j-1]+nums2[j-1]; 
                j++;
            }
        }
        
        return max(sum1[m],sum2[n])%1000000007;
    }
};