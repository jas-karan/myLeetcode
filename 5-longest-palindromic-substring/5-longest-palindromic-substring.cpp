class Solution {
public:
    string longestPalindrome(string s) {
        //we made a isPal array for storing whether
        //s(i...j) is palin
        //GAP method for traversing diagonals
        
        int n=s.length();
        bool dp[n][n];
        
        int maxLength = 0;
        string ans = "";
        
        //g=0 one char strings
        //g=1 two char strings and so on
        
        for(int g=0; g<n; g++){
            for(int i=0,j=g; j<n; i++,j++){
                if(g==0){
                    dp[i][j]=1;
                }
                else if(g==1){
                    dp[i][j] = s[i]==s[j];
                }
                else{
                    dp[i][j] = (s[i]==s[j])&&(dp[i+1][j-1]);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j] && j-i+1>maxLength){
                    maxLength = j-i+1;
                    ans = s.substr(i,maxLength);
                }
            }
        }
        
        return ans;
    }
};