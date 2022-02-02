// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int K) {
    // your code here
        int length=-1;
        unordered_map<int,int>window;
        
        int l=0;
        int r=0;
        
        while(r<s.length()){
            window[s[r]]++;
            
            while(l<r && window.size()>K){
                window[s[l]]--;
                if(window[s[l]]==0) window.erase(s[l]);
                l++;
            }
            
            r++;
            if(window.size()==K) length = max(length,r-l);
        }
        
        return length;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends