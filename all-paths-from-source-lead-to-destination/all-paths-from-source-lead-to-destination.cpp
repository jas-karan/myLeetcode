class Solution {
public:
    vector<int>vis;
    
    int dfs(vector<vector<int>>&gr,int src,int des){
        if(gr[src].size()==0) return src==des;
        
        if(vis[src]!=-1) return vis[src]==1?1:0;
        
        vis[src]=0; 
        for(int nbr:gr[src]){
            if(dfs(gr,nbr,des)==0) return false;
        }
        return vis[src]=1;
    }
    
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>gr(n);
        for(auto e:edges){
            gr[e[0]].push_back(e[1]);
        }
        vis=vector<int>(n,-1);
        return dfs(gr,source,destination);
    }
};