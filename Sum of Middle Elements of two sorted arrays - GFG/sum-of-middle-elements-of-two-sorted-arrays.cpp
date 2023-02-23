//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
            // code here 
            
            int l = 0, r = n;
            
            while(l<=r){
                int i = l+(r-l)/2;
                int j = n - i;
                int l1 = i==0 ? INT_MIN : ar1[i-1];
                int l2 = j==0 ? INT_MIN : ar2[j-1];
                int r1 = i==n ? INT_MAX : ar1[i];
                int r2 = j==n ? INT_MAX : ar2[j];
                
                if(l1<=r2 && l2<=r1) return max(l1,l2)+min(r1,r2);
                else if(l1>r2) r=i-1;
                else l=i+1;
            }
            
            return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends