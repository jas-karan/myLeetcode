class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0, n=stones.size();
        
        for(int i=0; i<n; i++){
            sum += stones[i];
        }
        
        bool dp[n+1][sum+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0) dp[i][j]=false;
                if(j==0) dp[i][j]=true;
            }
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(stones[i-1]<=j){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-stones[i-1]];
                }
                else
                    dp[i][j]=dp[i-1][j];
                }
        }
        vector<int> temp;
        int max_sum_of_half_array;
        for(int j=0; j<=(sum/2); j++){
            if(dp[n][j]==true){
                max_sum_of_half_array = j;
            }
        }
        
        int res = sum - (2*max_sum_of_half_array);
        return res;
    }
};