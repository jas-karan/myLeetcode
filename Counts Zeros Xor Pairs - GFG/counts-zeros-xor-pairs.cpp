// { Driver Code Starts
// C++ program to find number 
// of pairs in an array such
// that their XOR is 0
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the
// count
long long int calculate(int a[], int n);

// Driver Code
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
	  int n;
	  cin>>n;
	  int arr[n+1];
	  for( int i=0;i<n;i++)
	        cin>>arr[i];
	    cout << calculate(arr, n)<<endl;
        
	}
	return 0;
}

// } Driver Code Ends


long long int calculate(int a[], int m)
{
    //xor is zero when number is xored with itself
    
    int pairs=0;
    sort(a,a+m);
    
    int f=0,l=0;
    for(int i=1;i<m;i++){
        if(a[i]==a[i-1]) l=i;
        else{
            int n=l-f+1;
            pairs+=(n*(n-1)/2);
            f=i;
            l=i;
        }
    }
    int n=l-f+1;
    pairs+=(n*(n-1)/2);
    return pairs;
}
