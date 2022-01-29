// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int r=0,c=m-1;
	    int max_row=-1;
	    int max_1s=0;
	    
	    while(r<n&&c>=0){
	        if(arr[r][c]==1){
	            c--;
	        }
	        else{
	            if(m-c-1 > max_1s){
	                max_1s = m-c-1;
	                max_row = r;
	            }
	            r++;
	        }
	    }    
	    if(m-c-1>max_1s) max_row=r;
	    return max_row;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends