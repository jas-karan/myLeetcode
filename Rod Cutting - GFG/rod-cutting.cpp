// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int prices[], int n) {
        
        vector<int>dp(n+1);
        dp[0]=0;
        for(int i=1;i<=n;i++) dp[i]=prices[i-1];
        
        for(int i=1;i<=n;i++){
            for(int j=i;j>=0;j--){
                dp[i]=max(dp[i],prices[j-1]+dp[i-j]);
            }
        }
        
        return dp[n];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends