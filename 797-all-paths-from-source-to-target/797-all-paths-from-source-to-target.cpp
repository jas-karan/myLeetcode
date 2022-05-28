class Solution {
public: 
    vector<vector<int>>res;
    
    void dfs(int i,int n,vector<vector<int>>graph,vector<int>curr){
        if(i==n-1){
            res.push_back(curr);
            return;
        }
        
        for(int nbr:graph[i]){
            curr.push_back(nbr);
            dfs(nbr,n,graph,curr);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>curr;
        curr.push_back(0);
        dfs(0,graph.size(),graph,curr);
        
        return res;
    }
};