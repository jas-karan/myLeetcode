// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    //since matrices are sorted we can use two pointers
	    int lr=0,lc=0,rr=n-1,rc=n-1;
	    int count=0;
	    
	    while(lr<n && rr>=0){
	        int sum = mat1[lr][lc]+mat2[rr][rc];
	        
	        if(sum==x){
	            count++;
	            lc++;
	            rc--;
	        }
	        else if(sum<x){
	            lc++;
	        }
	        else{
	            rc--;
	        }
	        if(lc==n){
	           lr++;
	           lc=0;
	        }
	        if(rc<0){
	           rr--;
	           rc=n-1;
	        }
	    }
	    
	    return count;
	}
};

// { Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}  // } Driver Code Ends