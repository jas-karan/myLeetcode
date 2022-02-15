class Solution {
public:
//     int helper(string a,string b,int i,int j){
//         if(i<0 || j<0) return 0;
        
//         if(a[i]==b[j]) return 1 + helper(a,b,i-1,j-1);
        
//         return max(helper(a,b,i-1,j), helper(a,b,i,j-1));
//     }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        
        int dp[n1+1][n2+1];
        
        for(int i=0;i<=n1;i++) dp[i][0]=0;
        for(int i=0;i<=n2;i++) dp[0][i]=0;
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                
                if(text1[i-1] == text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n1][n2];
    }
};