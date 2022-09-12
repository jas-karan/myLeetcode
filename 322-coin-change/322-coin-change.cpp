class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<int>mem(amount+1,INT_MAX);
        mem[0] = 0;
        
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(coins[j]<=i){
                    if(mem[i-coins[j]]!=INT_MAX){
                        mem[i] = min(mem[i], 1+mem[i-coins[j]]);
                    }
                }
            }
        }
        
        return mem[amount]==INT_MAX ? -1 : mem[amount];
    }
};