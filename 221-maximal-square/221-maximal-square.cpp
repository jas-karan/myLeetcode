class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int dp[m][n];
        //dpi,j = by taking i,j as top left corner, max sqaure possible
        //therefore dpi,j = 0 if mati,j = 0
        
        //for forming a square,with top left at i,j
        //we have to add 1's to left, to diagonal and to bottom
        // _| shaped lines 
        //so we take minimum/weakest of three (bcoz we want sqaure) and add 1
        
        for(int i=0;i<m;i++) dp[i][n-1]=matrix[i][n-1]=='1'?1:0;
        for(int i=0;i<n;i++) dp[m-1][i]=matrix[m-1][i]=='1'?1:0;
        
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(matrix[i][j]=='0') dp[i][j]=0;
                else{
                    dp[i][j]=1+min(dp[i][j+1],min(dp[i+1][j+1],dp[i+1][j]));
                }
            }
        }
        
        int max_side = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) max_side=max(max_side,dp[i][j]);
        }
        
        return max_side*max_side;
    }
};