// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    vector<pair<int,int>>arr(n);
	    for(int i=0;i<n;i++){
	        arr[i].first = nums[i];
	        arr[i].second = i;
	    }
	    sort(arr.begin(), arr.end());
	    
	    vector<bool>vis(n,false);
	    int swaps = 0;
	    
	    for(int i=0;i<n;i++){
	        if(arr[i].second==i || vis[i]==true) continue;
	        
	        int c_len = 0;
	        int j = i;
	        while(vis[j]==false){
	            vis[j]=true;
	            c_len++;
	            j=arr[j].second;
	        }
	        swaps+=c_len-1;
	    }
	    
	    return swaps;
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
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends