// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        //take care of indices -l,h,m
        // it is very easy.
        return mergeSort(0,N-1,arr);
        
    }
    
    long long mergeSort(int l,int h,long long *arr){
        // think recursively
        if(l<h){
            int mid = (l+h)/2;
            long long left = mergeSort(l,mid,arr);  //get inversions from left
            long long right = mergeSort(mid+1,h,arr); //get inversions from right
            return left+right+merge(l,h,mid,arr);  //get inversions from merged left and right
        }
        else{   //if there is just one element (l==h) then zero inversions
            return 0;
        }
    }
    
    long long merge(int l,int h,int m,long long *arr){
        long long sorted[h-l+1];
        long long count = 0;
        int i=l,j=m+1,k=0;
        
        while(i<=m && j<=h){
            if(arr[i]<=arr[j]){
                sorted[k++] = arr[i++];
            }
            else{
                count+=(m-i+1);
                sorted[k++] = arr[j++];
            }
        }
        while(i<=m){
            sorted[k++] = arr[i++];
        }
        while(j<=h){
            sorted[k++] = arr[j++];
        }
        
        for(int i=l;i<=h;i++){
            arr[i] = sorted[i-l];
        }
        
        return count;
    }
    
};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends