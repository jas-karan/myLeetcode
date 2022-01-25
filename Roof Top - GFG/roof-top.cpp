// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find maximum number of consecutive steps 
    //to gain an increase in altitude with each step.
    int maxStep(int arr[], int N)
    {
       //Your code here
       int curr = 0;
       int res = 0;
       
       for(int i=1;i<N;i++){
           if(arr[i]>arr[i-1]){
               curr++;
           }
           else{
               res = max(res,curr);
               curr = 0;
           }
       }
       
       return max(res,curr);
    }
};

// { Driver Code Starts.


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    Solution ob;
	    cout << ob.maxStep(a, n) << endl;
	}
	return 0;
}  // } Driver Code Ends