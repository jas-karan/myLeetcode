// { Driver Code Starts
// C++ implementation of For each element in 1st 
// array count elements less than or equal to it
// in 2nd array
#include <bits/stdc++.h>
 
using namespace std;


 // } Driver Code Ends
// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
class Solution{
  public:
    int lse(int a[], int n, int ele){
        int l=0,h=n-1;
        int index=-1;
        while(l<=h){
            int m = l+ (h-l)/2;
            if(a[m]<=ele){
                index=m;
                l=m+1;
            }
            else h=m-1;
        }
        return index+1;
    }
  
    vector<int> countEleLessThanOrEqual(int a[], int b[], int m, int n)
    {
        sort(b,b+n);
        vector<int>res;
        
        for(int i=0;i<m;i++){
            int count = lse(b,n,a[i]);
            res.push_back(count);
        }
    
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int arr1[m],arr2[n];
        for(int i=0;i<m;i++)
        cin>>arr1[i];
        for(int j=0;j<n;j++)
        cin>>arr2[j];
        Solution obj;
        vector <int> res = obj.countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends