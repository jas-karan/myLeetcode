// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool possible(int a[],int n,int m,int max_pages){
        int students = 1;
        int allocated = 0;
        for(int i=0;i<n;i++){
            allocated+=a[i];
            if(allocated>max_pages){
                students++;
                allocated=a[i];
            }
        }
        
        return students<=m;
    }
    
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        //l should be max book size, bcoz that book must be allocated
        //so min those number of pages should be in search space
        int l = INT_MIN, h = 0;
        for(int i=0;i<n;i++){
            l = max(l,a[i]);
            h += a[i];
        }
        
        int max_pages = -1;
        while(l<=h){
            int mid = l+(h-l)/2;
            
            if(possible(a,n,m,mid)){
                max_pages = mid;
                h = mid-1;
            }
            else l = mid+1;
        }
        
        return max_pages;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends