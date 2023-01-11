//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool possible(int arr[], int n, int d,int w){
        int days = 1;
        int curr = 0;
        for(int i=0;i<n;i++){
            curr += arr[i];
            if(curr>w){
                days++;
                curr = arr[i];
            }
        }
        
        return days<=d;
    }
  
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        int l=0,r=0;
        for(int i=0;i<n;i++){
            l=max(l,arr[i]);
            r+=arr[i];
        }
        
        int w=0;
        while(l<=r){
            int m = l+(r-l)/2;
            
            if(possible(arr,n,d,m)){
                w=m;
                r=m-1;
            }
            else l=m+1;
        }
        
        return w;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends