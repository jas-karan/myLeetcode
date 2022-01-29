// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        sort(arr,arr+n);
        int triangles = 0;
        for(int i=n-1;i>=2;i--){
            int target=arr[i];
            int l=0,h=i-1;
            while(l<h){
                if(arr[l]+arr[h]>target){
                    //then for all the l<=j<h ,arr[j]+arr[h]>target
                    triangles+=(h-l);
                    h--;
                }
                else l++;   //or increase the sum 
            }
        }
        
        return triangles;
    }
};


// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}  // } Driver Code Ends