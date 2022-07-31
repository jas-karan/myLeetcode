class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                dp[i][j] = matrix[i][j]=='1'? dp[i][j+1]+1:0;
            }
        }
        
        int ans=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int colLen = n;
                for(int row = i;row<m;row++){
                    colLen = min(colLen,dp[row][j]);
                    ans=max(ans,(row-i+1)*colLen);
                }
            }
        }
        
        return ans;
    }
};