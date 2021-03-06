// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        //if sum becomes zero it is the max length subarray with sum = 0 
        //a b c : if sum from a to c is same as sum from a to b then sum from b to c is zero
        //else insert that sum only iff not present bcoz we want largest
        //updating the sum index will shorten the subarray
        
        
        int length=0;
        unordered_map<int,int>mp;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum==0) length=i+1;
            if(mp.find(sum)!=mp.end()){
                length=max(length,i-mp[sum]);
            }
            if(mp.find(sum)==mp.end()) mp[sum]=i;
        }
        return length;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends