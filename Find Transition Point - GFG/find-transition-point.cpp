// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    // code here
    int l=0,h=n-1;
    int trans=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]==1){
            trans=mid;
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    
    return trans;
}