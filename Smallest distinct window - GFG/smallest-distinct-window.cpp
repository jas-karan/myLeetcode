// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string findSubString(string s)
    {
        // Your code goes here 
        unordered_set<char>unique;
        for(char ch:s) unique.insert(ch);
        int reqCount=unique.size();
        
        unordered_map<char,int>window;
        int length=INT_MAX;
        string smallest = "";
        
        int foundCount = 0;
        int l=0,r=0;
        
        while(r<s.length()){
            window[s[r]]++;
            if(unique.find(s[r])!=unique.end()&&window[s[r]]==1) foundCount++;
            //second condition is to avoid duplicates
            
            r++;
            
            //shrink window only if all the req count is found
            while(reqCount==foundCount && l<r){
                if(length>r-l){
                     length=r-l;
                     smallest = s.substr(l,length);
                }
                window[s[l]]--;
                
                //if deleting the char makes its count in window 0, reduce the foundcount
                if(unique.find(s[l])!=unique.end() && window[s[l]]==0) foundCount--;
                l++;
            }
        }
        
        return smallest;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
}  // } Driver Code Ends