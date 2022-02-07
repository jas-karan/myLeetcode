// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // bool helper(int arr[],int i,int sum){
    //     if(sum==0) return true;
    //     if(i<=0) return false;
        
    //     return helper(arr,i-1,sum)||helper(arr,i-1,sum-arr[i-1]);
    // }

    bool helper(int arr[],int n,int sum, vector<vector<int>>&dp){
        if(sum==0) return 1;
        if(n<=0) return 0;
        
        if(dp[n][sum]!=-1) return dp[n][sum];
        
        return dp[n][sum] = helper(arr,n-1,sum,dp)||helper(arr,n-1,sum-arr[n-1],dp);
    }

    bool isSubsetSum(int N, int arr[], int sum){
        // return helper(arr,N,sum);
        
        //in rec call, we are looking for whether with i-1 elements is subset with sum possible?
        
        //store this in dp array
        
        vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
        return helper(arr,N,sum,dp);
        
        
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends