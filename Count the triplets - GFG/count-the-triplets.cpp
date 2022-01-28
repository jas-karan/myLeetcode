// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	    sort(arr,arr+n);
	    int triplets = 0;
	    
	    for(int i=n-1;i>=2;i--){
	        int target=arr[i];
	        
	        int l=0,h=i-1;
	        while(l<h){
	            if(arr[l]+arr[h]==target){
	                triplets++;
	                l++;h--;
	            }
	            else if(arr[l]+arr[h]<target){
	                l++;
	            }
	            else h--;
	        }
	    }
	    
	    return triplets;
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
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}  // } Driver Code Ends