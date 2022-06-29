class Solution {
public:
    bool winnerSquareGame(int n) {
        //dpi = result for n=i
        //if alice removes some k*k stones where k*k<=i 
        //left stones = i-k*k and 
        //if dp[left stones]=false ie bob lose as he will also play optimally
        //then alice wins
        
        vector<bool>dp(n+1,false);
        
        for(int i=1;i<=n;i++){
            for(int k=1;k*k<=i;k++){
                if(dp[i-k*k]==false){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};