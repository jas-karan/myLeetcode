// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string s){
		    // we have to find 2 common longest sequences such that index of a char in one
		    //is different from index of corresponding char in second.
		    
		    //so simply find LCS of s and s 
		    //but that will be the whole string
		    //no! here we check if chars are equal and are not at same index !!
		    
		    int n = s.length();
		    int dp[n+1][n+1];
		    for(int i=0;i<=n;i++){
		        dp[i][0]=dp[0][i]=0;
		    }
		    
		    for(int i=1;i<=n;i++){
		        for(int j=1;j<=n;j++){
		            if(s[i-1]==s[j-1] && i!=j){
		                dp[i][j]=dp[i-1][j-1]+1;
		            }
		            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		        }
		    }
		    
		    return dp[n][n];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends