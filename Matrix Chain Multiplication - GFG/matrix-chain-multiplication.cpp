// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        // given three matrices - A,B,C (in chain - order in which they can be multiplied)
        // (A*B)*C and A*(B*C) - muliplications required for both will be different
        // A = 2*3 B = 3*4 C = 4*5  or given [2,3,4,5]
        // multiplications for (A*B)*C = 2*3*4 + 0 +2*4*5 = 64
        // multiplications for A*(B*C) = 3*4*5 + 0 + 2*3*5 = 90
        // min = 64
        
        //(A*B)*(C*D*E) = l + r + (muliplying both)
        // store l and r
        
        //if arr.size = n+1 then n matrices
        //upper dp-matrix only -  n rows and n cols
        //0 to n-1 one for each matrix
        //dp[i][j] = min muls for muls of matrices i to j
        //dimensions of matrix i will be arr[i]*arr[i+1]
        
        //dp[i][i] = 0, no muls reqd for one matrix
        //dp[i][i+1] = arr[i]*arr[i+1]*arr[i+2] for each i = 0 to n-2
        
        //gap wise-> first 0 (A), then 1 (eg.AB), 2 (ABC), diagonally upwards
        
        int dp[n-1][n-1];
        
        for(int g=0;g<n-1;g++){ //to move upward diagonally
        
            for(int i=0,j=g; j<n-1; i++,j++){ // traverse the diagonal
                
                if(g==0) dp[i][j]=0;  //first diagonal
                else if(g==1) dp[i][j]=arr[i]*arr[j]*arr[j+1];  //second diagonal
                
                //else there are multiple ways to multiply
                else{
                    int minCost = INT_MAX;
                    for(int k=i;k<j;k++){
                        //left i to k, right k+1 to j
                        //size: left=arr[i]*arr[k+1], right=arr[k+1]*arr[j+1]
                        
                        int l = dp[i][k];
                        int r = dp[k+1][j];
                        int m = arr[i]*arr[k+1]*arr[j+1];
                        int total = l+r+m;
                        
                        minCost = min(minCost,total);
                        
                    }
                    dp[i][j] = minCost;
                }
            }
        }
    
        return dp[0][n-2];    
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends