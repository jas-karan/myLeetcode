// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
public:
	int countZeros(vector<vector<int>>A)
	{
		//similar to search in sorted matrix - two
		//rows and cols are sorted
		int n = A.size();
		
		int zeroes = 0;
		int i=0,j=n-1;
		//starting from top right corner
		while(i<n && j>=0){
		    if(A[i][j]==1){
		        //then this column is useless (no zeroes in it)
		        j--;
		    }
		    else{
		        //then all the elements in ith row till jth column must be zeroes
		        zeroes += (j+1);
		        i++;
		    }
		}
		
		return zeroes;
		
	}
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>>A(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                cin>>A[i][j];
            }
        }
        Solution ob;
        cout<<ob.countZeros(A)<<'\n';
    }
    return 0;
}
  // } Driver Code Ends