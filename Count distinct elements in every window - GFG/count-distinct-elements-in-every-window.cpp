// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int a[], int n, int k)
    {
        vector<int>count;
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++) mp[a[i]]++;
        count.push_back(mp.size());
        
        for(int i=k;i<n;i++){
            mp[a[i-k]]--;
            if(mp[a[i-k]]==0) mp.erase(a[i-k]);
            mp[a[i]]++;
            count.push_back(mp.size());
        }
        
        return count;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends