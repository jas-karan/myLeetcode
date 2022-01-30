// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector<int> square(int arr[], int n);


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n+1];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        vector<int> ans;
        ans = square(arr, n);
        for(int i:ans)
            cout << i << " ";
        cout << endl;
        
    }
    return 0;
}
// } Driver Code Ends


//similar to count xor pairs ---
vector<int> square(int arr[], int n)
{
    sort(arr,arr+n);
    int area=INT_MIN,count=0;
    int curr = 1;
    for(int i=0;i<n;i++){
        if(arr[i]==arr[i-1]){
            curr++;
        }
        else{
            if(curr>=4){
                area=max(area,arr[i-1]*arr[i-1]);
                count=(curr/4);
            }
            curr=1;
        }
    }
    if(curr>=4){
        area=max(area,arr[n-1]*arr[n-1]);
        count=curr/4;
    }
    if(count==0) return {-1};
    return {area,count};
}
