class Solution {
public:
    unordered_map<int,int>color;
        
    queue<pair<int,int>>q;
    
    bool bfs(int root,vector<vector<int>>graph){
        
        q.push({root,1});
        color[root]=1;
        
        while(!q.empty()){
            int sz = q.size();
            
            for(int i=0;i<sz;i++){
                
                auto curr = q.front(); q.pop();
                
                for(int nbr:graph[curr.first]){
                    
                    if(color.find(nbr)!=color.end()){
                        if(color[nbr] == curr.second){
                            return false;
                        }
                    }
                    else{
                        color[nbr]=-1*(curr.second);
                        q.push({nbr,-1*(curr.second)});
                    }
                }
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();   
        
        for(int i=0;i<n;i++){
            if(color.find(i)==color.end()){
                bool ans = bfs(i,graph);
                if(!ans) return false;
            }
        }
        
        return true;
    }
};