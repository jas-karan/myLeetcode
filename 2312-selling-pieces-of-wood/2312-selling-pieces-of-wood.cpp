class Solution {
public:
    vector<vector<int> > cost;
    vector<vector<long long> > dp;
    
    long long sellingWood(int n, int m, vector<vector<int>>& prices) {
        
        cost.assign(n+1, vector<int> (m+1, -1));
        for(int i=0;i<prices.size();i++) {
            cost[prices[i][0]][prices[i][1]] = max(cost[prices[i][0]][prices[i][1]], prices[i][2]);            
        }
        
        dp.assign(n+1, vector<long long> (m+1, -1));
                
        long long ans = getans(n, m);
        return ans;
    }
    
    long long getans(int row, int col) {
        if(row == 1 && col == 1) {
            if(cost[1][1] != -1)
                return cost[1][1];
            return 0;
        }
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        
        long long ans = cost[row][col] == -1 ? 0 : cost[row][col];
        
        for(int i = 1; i < row; i++) {
            long long curr = getans(i, col) + getans(row - i, col);
            ans = max(ans, curr);
        }
        
        for(int i = 1; i < col; i++) {
            long long curr = getans(row, i) + getans(row, col - i);
            ans = max(ans, curr);
        }
        
        dp[row][col] = ans;
        return ans;
    }
};