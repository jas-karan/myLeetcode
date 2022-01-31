class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int rich = INT_MIN;
        int c = accounts.size(),b=accounts[0].size();
        for(int i=0;i<c;i++){
            int sum=0;
            for(int j=0;j<b;j++){
                sum+=accounts[i][j];
            }
            rich = max(rich,sum);
        }
        
        return rich;
    }
};