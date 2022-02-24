// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    stack<int>stck;
    unordered_set<int>visited;
    
    void order(vector<int>adj[],int v){
        
        visited.insert(v);
        
        for(int nbd:adj[v]) if(visited.find(nbd)==visited.end()) order(adj,nbd);
        
        stck.push(v);
    }
    
    void dfs(vector<int>adj[],int v){
        
        visited.insert(v);
        
        for(int nbd:adj[v]) if(visited.find(nbd)==visited.end()) dfs(adj,nbd);
    }
    
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // store dfs in stack
	    // top node in stack will be minimum mother vertex in graph
	    // will also be first node in topological sorting
	    // same method is also used in kosaraju for find SCC's
	    
	    for(int i=0;i<V;i++){
	        if(visited.find(i)==visited.end()) order(adj,i);
	    }
	    
	    visited.clear();
	    
	    dfs(adj,stck.top());
	    
	    if(visited.size()!=V) return -1;
	    
	    return stck.top();
	    
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends