class Solution {
public:
    vector<vector<int>>dir={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    
    double dfs(int N, int K, int r, int c, vector<vector<vector<double>>> & dp){
        
        if(r < 0 || c < 0 || r >= N || c >= N) return 0;
        if(K == 0) return 1;
        if(dp[r][c][K] != -1) return dp[r][c][K];
        
        double sum = 0.0;
        for(auto d:dir){
            sum+= 0.125*dfs(N,K-1,r+d[0],c+d[1],dp);
        }
        
        dp[r][c][K] = sum;
        return dp[r][c][K];
    }
    
    double knightProbability(int N, int K, int r, int c) {
        
        vector<vector<vector<double>>> dp(N + 1, vector<vector<double>> (N + 1, vector<double>(K + 1, -1)));
        
        return dfs(N, K, r, c, dp);
    }
};