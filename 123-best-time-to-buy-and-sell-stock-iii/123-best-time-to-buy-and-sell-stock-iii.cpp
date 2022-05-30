class Solution {
public:
//     int dfs(int txnleft,vector<int>prices,int ind,vector<vector<int>>&memo){
//         if(txnleft==0 || ind>=prices.size()) return 0;
        
//         if(memo[ind][txnleft]!=-1) return memo[ind][txnleft];
        
//         int ans1=dfs(txnleft,prices,ind+1,memo);
        
//         bool buy=false;
//         if(txnleft%2==0) buy=true;
        
//         int ans2;
//         if(buy) ans2=-prices[ind]+dfs(txnleft-1,prices,ind+1,memo);
//         else ans2=prices[ind]+dfs(txnleft-1,prices,ind+1,memo);
        
//         return memo[ind][txnleft] = max(ans1,ans2);
//     }
    
    int maxProfit(vector<int>& prices) {
//         int k=2;
//         int txnleft=2*k;
        
//         vector<vector<int>> memo(prices.size(), vector<int>(5, -1));
        
//         return dfs(txnleft,prices,0,memo);
        
        int dp[prices.size() + 1][5];
        
        
        for(int day = (int) prices.size();day >= 0;day--){
            
            for(int transactionsLeft = 0;transactionsLeft <= 4;transactionsLeft++){
                
                int &ans = dp[day][transactionsLeft];
                
                if(day == prices.size()){
                    ans = 0;
                }else if(transactionsLeft == 0){
                    ans = 0;
                }else{
                    
                    // choice 1
                    // no transaction today
                    int ans1 = dp[day + 1][transactionsLeft];
                    
                    // choice 2
                    // doing the possible transaction today     
                    int ans2 = 0;
                    bool buy = (transactionsLeft % 2 == 0);

                    if(buy == true){ // buy
                        ans2 = -prices[day] + dp[day + 1][transactionsLeft - 1];
                    }else{ // sell
                        ans2 = prices[day] + dp[day + 1][transactionsLeft - 1];
                    }

                    ans = max(ans1, ans2);

                }
                
            }
        }
        return dp[0][4];
    
    }
};