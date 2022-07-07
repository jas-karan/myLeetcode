class Solution {
public:
   
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        
        queue<pair<int,vector<int>>>q;
        q.push({0,{0}});
        vector<vector<int>>res;
        
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            
            if(cur.first==n-1){
                res.push_back(cur.second);
                continue;
            }
            
            for(int nbr:graph[cur.first]){
                cur.second.push_back(nbr);
                q.push({nbr,cur.second});
                cur.second.pop_back();
            }
        }
        
        
        return res;
    }
};