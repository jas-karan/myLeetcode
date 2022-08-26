class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& road) {
        vector<int>degree(n,0);
        set<pair<int,int>>s;
        for(auto r:road){
            degree[r[0]]++;
            degree[r[1]]++;
            s.insert({r[0],r[1]});
        }
        
        int rank=INT_MIN;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int curr=degree[i]+degree[j];
                if(s.find({i,j})!=s.end() || s.find({j,i})!=s.end()){
                    curr--;
                }
                rank=max(rank,curr);
            }
        }
        
        return rank;
    }
};