class Solution {
public:
    unordered_set<int>vis;
    
    void dfs(vector<vector<int>>&graph, int src){
        
        if(vis.find(src)!=vis.end()) return;
        vis.insert(src);
        
        for(int j=0;j<graph.size();j++){
            if(graph[src][j]){
                dfs(graph,j);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>&graph) {
        int n = graph.size();
        int count = 0;
        
        for(int i=0;i<n;i++){
            if(vis.find(i)==vis.end()){
                dfs(graph,i);
                count++;
            }
        }
        
        return count;
    }
};