class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        //i<j<k - sorting has no effect - since we are adding only
        //multiplicity - for duplicates let m duplicates of arr[j] and n of arr[k] then m*n pairs
        //special case - if(arr[j]==arr[k]) then whole window[j:k+1] is same 
        //then we cannot simply multiply m*n but we add total correct pairs - m*(m-1)/2 or n*(n-1)/2
        
        int n = A.size();
        sort(A.begin(), A.end());
        int ans = 0; 
        int mod = 1e9+7;
        
        for (int i=0; i<n-2; ++i) {
            int lo = i+1, hi = n-1;
            
            while (lo < hi) {
                
                if (A[i] + A[lo] + A[hi] == target) {
                    
                    int cntlo=1, cnthi=1;
                    
                    while (lo < hi && A[lo] == A[lo+1]) {cntlo++; lo++;}
                    while (lo < hi && A[hi] == A[hi-1]) {cnthi++; hi--;}
                    
					// A[lo]==A[hi] : same element window
                    if (lo == hi) ans =(ans+cntlo*(cntlo-1)/2)%mod;
                    
					// A[lo]!=A[hi]
                    else ans = (ans+cntlo*cnthi)%mod;
                    
                    lo++; hi--; 
                    
                } 
                else if (A[i] + A[lo] + A[hi] > target) {
                    hi--;
                } 
                else {
                    lo++;
                }
            }
        }
        return ans;
    }
};