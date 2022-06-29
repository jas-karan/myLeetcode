class Solution {
public:
    const int INF = 100 * 10000; // maximum distance = N * MAX_POS = 100 * 10^4 = 10^6
    int costs[100][100] = {};
    int memo[100][100] = {};
    
    int dfs(vector<int>& houses, int n, int k, int i){
        if (k == 0 && i == n) return 0;
        if (k == 0 || i == n) return INF;
        if (memo[k][i] != -1) return memo[k][i];
        int ans = INF;
        for (int j = i; j < n; j++)
            ans = min(ans, costs[i][j] + dfs(houses, n, k-1, j + 1));
        return memo[k][i] = ans;
    }
    
    int minDistance(vector<int>& houses, int k) {
        //idea is to divide the houses into k groups
        //apply recursion on finding those optimal groups
        //cost[i][j] = ans for single group of houses from i to j
        //mailbox should be at median of group
         
        int n = houses.size();
        sort(houses.begin(), houses.end());
        memset(memo, -1, sizeof(memo));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int medianPos = houses[(i + j) / 2];
                for (int m = i; m <= j; m++)
                    costs[i][j] += abs(medianPos - houses[m]);
            }
        }
        return dfs(houses, n, k, 0);
        
    }
};