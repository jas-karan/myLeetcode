class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy=INT_MAX;
        for(int p:prices){
            if(p<buy) buy=p;
            else profit = max(profit,p-buy);
        }
        return profit;
    }
};