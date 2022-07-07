class Solution {
public:
    unordered_set<int>vis;
    
    bool dfs(vector<vector<int>>&gr,int src,int des){
        if(src==des) return true;
        
        vis.insert(src);
        
        for(int nbr:gr[src]){
            if(vis.find(nbr)==vis.end()){
                if(dfs(gr,nbr,des)) return true;
            }
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>gr(n);
        
        for(auto e:edges){
            gr[e[0]].push_back(e[1]);
            gr[e[1]].push_back(e[0]);
        }
        
        return dfs(gr,source,destination);
    }
};