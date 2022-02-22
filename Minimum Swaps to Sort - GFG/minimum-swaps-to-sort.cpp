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
	    
	    int swaps = 0;
	    
	    //i is new pos, arr[i].second is old pos
	    
	    for(int i=0;i<n;i++){
	        int num = arr[i].first;
	        int idx= arr[i].second;
	        if(i!=idx){
	            //not in position
	            swaps++;
	            swap(arr[i],arr[idx]);
	            i--; //what if that is also not correct ele to be here
	        }
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