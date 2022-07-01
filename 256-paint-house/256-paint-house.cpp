class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        for(int i=1;i<costs.size();i++){
            for(int j=0;j<3;j++){
                int curr=INT_MAX;
                
                for(int k=0;k<3;k++){
                    if(k!=j){
                        curr=min(curr,costs[i-1][k]);
                    }
                }
                
                costs[i][j]+=curr;
            }
        }
        
        int cost=INT_MAX;
        for(int j=0;j<3;j++) cost=min(cost,costs[costs.size()-1][j]);
        
        return cost;
    }
};