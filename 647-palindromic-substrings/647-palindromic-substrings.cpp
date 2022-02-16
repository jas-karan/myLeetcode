class Solution {
public:
    int countSubstrings(string s) {
        //we cannot store subsequences --they are many many,
        //so we have to store palindrome subsequence count for substrings, bcoz
        //we can store all the substrings in upper matrix
        //and whether they are palindromes or not, it also.
        
        int n = s.length();
        bool isPal[n][n];
        int count=0;
        
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0) isPal[i][j]=true;
                else if(g==1) isPal[i][j]=(s[i]==s[j]);
                else{
                    if(s[i]==s[j] && isPal[i+1][j-1]) isPal[i][j]=true;
                    else isPal[i][j]=false;
                }
                
                if(isPal[i][j]) count++;
            }
        }
        
        return count;
    }
};