// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    //similar to laongest subarray with sum k
	    //a b c: if remainder of sum(a,b) is x and rem of sum(a,c) is also x
	    //then sum(b,c) has rem 0 ie, divisible by k =>
	    //sum(a,b)=k*m+x  and sum(a,c)=k*n+x
	    //sum(b,c) = sum(a,c)-sum(a,b) = k*n+x-k*m-x = k(n-m) which is divisible by k
	    
	    //but samething will not be true with negative numbers bcoz rem will become negative
	    //eg. k=7 then -5%7 = -5 
	    //basically we keep rem from 0 to k-1
	    //so when rem<0 add k to it :basics
	    
	    //we store last seen of rem in map
	    unordered_map<int,int>mp;
	    int length=0;
	    int sum = 0,rem;
	    
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	        rem=sum%k;
	        if(rem<0) rem+=k;
	        
	        if(rem==0) length=i+1;
	        if(mp.find(rem)!=mp.end()) length=max(length,i-mp[rem]);
	        if(mp.find(rem)==mp.end()) mp[rem]=i;
	    }
	    
	    return length;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends