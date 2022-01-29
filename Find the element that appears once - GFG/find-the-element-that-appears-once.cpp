// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int a[], int n){
	    //code
	    int l=0,h=n-1;
	    while(l<=h){
	        int mid=l+(h-l)/2;
	        
	        if(mid%2!=0 && a[mid]!=a[mid-1]) h=mid-1;
	        else if(mid%2==0 && a[mid]!=a[mid+1]) h=mid-1;
	        else l=mid+1; 
	    }
	    return a[l];
	}
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}
  // } Driver Code Ends