// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // similar as longest increasing subsequence
	    // lis[i] = max length of sequence ending at nums[i]
	    // once increasing sequence ends at nums[i]
	    // now we need a decreasing sequence starting from nums[i]
	    // we can also store lds[i] = longest decreasing subsequence start from nums[i]
	    
	    int n = nums.size();
	    vector<int>lis(n,1);
	    vector<int>lds(n,1);
	    
	    for(int i=0;i<n;i++){
	        for(int j=i-1;j>=0;j--){
	            if(nums[j]<nums[i]){
	                lis[i]=max(lis[i],1+lis[j]);
	            }
	        }
	    }
	    
	    //lds[i] depends on all j>i, so we have to start from back
	    for(int i=n-1;i>=0;i--){
	        for(int j=i+1;j<n;j++){
	            if(nums[j]<nums[i]){
	                lds[i]=max(lds[i],1+lds[j]);
	            }
	        }
	    }
	    
	    int maxLength = 1;
	    for(int i=0;i<n;i++){
	        maxLength = max(maxLength, lis[i]+lds[i]-1);
	    }
	    
	    return maxLength;
	}
	
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends