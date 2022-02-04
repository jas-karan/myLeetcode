// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //equal number of 0 and 1 ?
        //convert o to -1 then -1's will cancel 1's
        //find count of subarrays with sum=0
        
        unordered_map<int,int>mp;
        int sum=0;
        long long count=0;
        
        for(int i=0;i<n;i++){
            sum += (arr[i]==0)? -1:1;
            if(sum==0) count++;
            
            if(mp.find(sum)!=mp.end()) count+=mp[sum];
            
            mp[sum]++;
        }
        
        return count;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends