// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        //from (i,j) choose maxGold of three (i,j+1) (i-1,j+1) (i+1,j+1)
        //which also depends on max of their next three's
        
        //if you are at last col, you have only that cells gold, as you cannot go anywhere
        
        int dp[n][m];
        for(int i=0;i<n;i++) dp[i][m-1]=M[i][m-1];
        
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<n;j++){
                dp[j][i] = dp[j][i+1];
                if(j>0) dp[j][i]=max(dp[j][i],dp[j-1][i+1]);
                if(j<n-1) dp[j][i]=max(dp[j][i], dp[j+1][i+1]);
                
                dp[j][i]+=M[j][i];
            }
        }
        
        int maxGold=0;
        for(int i=0;i<n;i++) maxGold=max(maxGold,dp[i][0]);
        
        return maxGold;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends