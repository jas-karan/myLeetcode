// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        //if sum becomes k it is the max length subarray with sum = k
        //a b c : if sum from a to c is S and sum from a to b is S-k then sum from b to c is k
        //else insert that sum only iff not present bcoz we want largest
        //updating the sum index will shorten the subarray
        
        int length=0;
        unordered_map<int,int>mp;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum==k) length=i+1;
            else if(mp.find(sum-k)!=mp.end()){
                length=max(length,i-mp[sum-k]);
            }
            if(mp.find(sum)==mp.end()) mp[sum]=i;
        }
        return length;
        
    } 

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends