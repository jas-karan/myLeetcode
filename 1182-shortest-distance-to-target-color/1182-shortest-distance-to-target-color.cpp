class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<vector<int>>map(4);
        for(int i=0;i<colors.size();i++)
            map[colors[i]].push_back(i);
        
        vector<int>res;
        for(auto&q:queries){
            int ind=q[0];
            int c=q[1];
            if(map[c].size()==0){
                res.push_back(-1);
                continue;
            }
            vector<int>&cur=map[c];
            int j=lower_bound(begin(cur),end(cur),ind)-begin(cur);
            int ans=INT_MAX;
            
            if(j<cur.size()) ans=cur[j]-ind;
            if(j!=0) ans=min(ans,ind-cur[j-1]);
            
            res.push_back(ans);
        }
        
        return res;
    }
};