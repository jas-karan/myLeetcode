class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //it is same as finding lcs of s and reverse of s
        
        //or
        //results for lps of s(i..j) using GAP method
        //one char string for example "a" is always palindrome
        //two char string for eg. "ab"- has 4 possible sequences - "","b" ,"a","ab"
        //if two chars are equal => longest is 2, else 1
        
        
        
        int n = s.length();
        int dp[n][n];
        
        for(int g=0;g<n;g++){
            
            for(int i=0,j=g; j<n; i++,j++){
                
                if(g==0) dp[i][j]=1; 
                else if(g==1){
                    dp[i][j]= (s[i]==s[j])?2:1; 
                }
                else{
                    if(s[i]==s[j]) dp[i][j]=2+dp[i+1][j-1]; //s[i]ands[j](2 char) added
                    
                    else dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
                    //exclude s[i] and s[j] and take max
                }
                
            }
        }
        
        return dp[0][n-1];
    }
};