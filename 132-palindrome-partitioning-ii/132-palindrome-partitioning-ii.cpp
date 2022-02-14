// *************important************** 
// note this gap method (traversing diagonal wise)(using upper half triangle)
// to store result array(i...j)

//used in matrix chain multiplication, balloon burst, boolean parenthesisation
//and lots of string questions

class Solution {
public:
    int minCut(string s) {
        //idea : "aabc" - three positions for cut
        // a|abc or aa|bc or aab|c
        //for each , left part and right part have there minCuts let l and r
        //so find 1+l+r for each cut and choose min
        
        //store l and r in dp
        
        int n = s.length();
        bool isPal[n][n]; //to store if s(i..j) is palindrome
        
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                
                if(g==0) isPal[i][j] = 1; //single char is palindrome
                
                else if(g==1) isPal[i][j] = s[i]==s[j];  //two char string
                
                else{
                    isPal[i][j] = (s[i]==s[j] && isPal[i+1][j-1]); 
                    //first and last char same and middle is also palindrome
                }
            }
        }
        
//         int dp[n][n];
//         for(int g=0;g<n;g++){
//             for(int i=0,j=g;j<n;i++,j++){
//                 if(isPal[i][j]) dp[i][j]=0;  //if palindrome no partitioning is reqd
//                 else{
//                     dp[i][j]=INT_MAX;
//                     for(int k=i;k<j;k++){
//                         dp[i][j] = min(dp[i][j], 1+dp[i][k]+dp[k+1][j]);
//                     }
//                 }
//             }
//         }
        
//         return dp[0][n-1];
        
        
// O(n^3)
//  ---------- although time limit exceeded,, but it great intuition ----------
        
        //dp[j] = minCuts till s[j]
        //for string s(0..j) find suffix s(i..j) which is palindrome
        //for all this palindromic suffices
        //find min of 1+dp[i-1]
        
        int dp[n];
        dp[0]=0;
        
        for(int j=1;j<n;j++){
            if(isPal[0][j]){
                dp[j]=0;
            }
            else{
                dp[j]=INT_MAX;
                for(int i=j;i>=1;i--){
                    if(isPal[i][j]){
                        dp[j]=min(dp[j],1+dp[i-1]);
                    }
            }
            }
        }
        
        return dp[n-1];
        
    }
};