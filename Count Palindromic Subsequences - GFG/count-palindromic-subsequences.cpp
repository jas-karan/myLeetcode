// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int MOD = 1e9+7;
    /*You are required to complete below method */
    long long int  countPS(string s)
    {
       //results for cps of s(i..j) using GAP method
        //one char string for example "a" has 2 sequences - "" and "a", take nonempty (1)
        //two char string for eg. "ab"- has 4 possible sequences - "","b" ,"a","ab"
        //if two chars are equal => count is 3, else 2
        
        //for rest of length substrings =>
        //if s[i]==s[j] => add s[i] to s(i+1..j-1) + add s(i+1,..j-1) to s[j] + add both s[i]and s[j]
        //but when we take first two only,, count of palindromes when both s[i]and s[j] are added
        //will already be counted.. (remember we are storing count of *subsequences*)
        //we have to add 1 --for subsequence = "s[i]s[j]"
        
        //if s[i]!=s[j] => exclude s[i] + exclude s[j] - (count of middle part)
        //because added two times with s[i] and s[j];
        
        int n = s.length();
        long long int dp[n][n];
        
        for(int g=0; g<n; g++){
            for(int i=0,j=g ;j<n; i++,j++){
                
                if(g==0) dp[i][j]=1;
                else if(g==1) dp[i][j] = (s[i]==s[j]) ? 3:2;
                else{
                    if(s[i]==s[j]) dp[i][j]=((dp[i+1][j])%MOD +((dp[i][j-1])%MOD +1)%MOD)%MOD;
                    else dp[i][j] = ((dp[i+1][j])%MOD +(dp[i][j-1])%MOD -(dp[i+1][j-1])%MOD)%MOD;
                }
                
                if(dp[i][j]<0) dp[i][j]+=MOD;
            }
        }
        
        return (dp[0][n-1])%MOD;
        
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends