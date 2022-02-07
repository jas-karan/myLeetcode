// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    // int helper(int W,int wt[],int val[],int n){
    //     if(W<=0) return 0; //if bag has no capacity
    //     if(n==0) return 0; //if there is nothing to pick
        
    //     if(wt[n-1]>W) return helper(W,wt,val,n-1); //if this item cannot be picked
        
    //     return max(val[n-1]+helper(W-wt[n-1],wt,val,n-1), helper(W,wt,val,n-1));
    // }
    
    int helper(int W,int wt[],int val[],int n, vector<vector<int>>&dp){
        if(W<=0) return 0;
        if(n==0) return 0;
        
        if(dp[n][W]!=-1) return dp[n][W];
        
        if(wt[n-1]>W){
            dp[n][W] = helper(W,wt,val,n-1,dp);
        }
        
        else dp[n][W] = max(val[n-1]+helper(W-wt[n-1],wt,val,n-1,dp), helper(W,wt,val,n-1,dp));
        return dp[n][W];
        
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    //   return helper(W,wt,val,n);
    
    //store the pverlapping problems in dp
    
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        return helper(W,wt,val,n,dp);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends