//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    // Code here.
	    int n = nums.size();
	    vector<int>smaller(n,0);
	    for(int i=0;i<n;i++) for(int j=0;j<i;j++) if(nums[j]<nums[i]) smaller[i]+=1;
	    vector<int>greater(n,0);
	    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(nums[i]<nums[j]) greater[i]+=1;
	    int sum = 0;
	    for(int i=0;i<n;i++) sum+=smaller[i]*greater[i];
	    
	    return sum;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends