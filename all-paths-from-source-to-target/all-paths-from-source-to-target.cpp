class Solution {
public:
    vector<vector<int>>res;
    int n;
    bool vis[16]={false};
    
    void dfs(vector<vector<int>>& graph,int node,vector<int>curr){
        if(node==n-1){
            curr.push_back(n-1);
            res.push_back(curr);
            return;
        }
        
        vis[node]=true;
        curr.push_back(node);
        
        for(int nbr:graph[node]){
            if(vis[nbr]==false) dfs(graph,nbr,curr);
        }
        
        vis[node]=false;
        curr.pop_back() ; 
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<int>curr;
        n=graph.size();
        dfs(graph,0,curr);
        return res;
    }
};