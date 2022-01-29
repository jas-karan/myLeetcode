// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int distinctCount(int arr[], int n) {
       int l=0,r=n-1;
       
       //store prev left and right to exclude duplicates
       int prev_l=INT_MIN, prev_r=INT_MAX;
       int count=0;
       
       
       while(l<=r){
           int left=abs(arr[l]);
           int right=abs(arr[r]);
           
           if(left==right){
               //if equal and already not taken then increase count and move inwards
               if(right!=prev_r && left!=prev_l){
                   count++;
               }
               r--; l++;
               prev_l=left; prev_r=right;
           }
           else if(left<right){
               if(right!=prev_r) count++;
               prev_r = right;
               r--;
           }
           else{
               if(left!=prev_l) count++;
               prev_l = left;
               l++;
           }
       }
       
       return count;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.distinctCount(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

  // } Driver Code Ends