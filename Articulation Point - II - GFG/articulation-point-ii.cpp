// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

        // a node i is AP if nodes after i are not able to touch nodes before i
        // or there is no other path between after and before nodes
        // so we maintain two arrays low[] and disc[]
        // disc[] stores discovery time of node in dfs
        // low[] stores lowest node that this node can reach (except path from where i is reached)
        // so if for node i,if any of its nbr j, low[j]>=disc[i] it is articulation point
        // bcoz all the node before i will have disc time less than disc time of i
        // so if any nbr is not able to reach before nodes, i is AP
        
        // disc time of source is 1 and low will also be 1, bcoz it is the lowest node
        // in graph. thus no need to optimise it
        

class Solution {
  public:
    unordered_set<int>vis;
    
    void dfs(int u,vector<int>adj[],vector<int>&disc,vector<int>&low,vector<bool>&ap,int timee,int parent){
        disc[u] = timee;
        low[u] = timee;
        vis.insert(u);
        int count = 0; //for src node(0) only
        for(int nbd:adj[u]){
            
            if(parent==nbd){ //that will be path that we came thru
                continue;
            }
            else if(vis.find(nbd)!=vis.end()){ //visited, must have less disc
                low[u] = min(low[u],disc[nbd]);
            }
            else{
                count++;
                dfs(nbd,adj,disc,low,ap,timee+1,u);
                low[u] = min(low[u],low[nbd]);
                if(parent==-1){
                    if(count>=2) ap[u]=true;
                }
                else{
                    if(low[nbd]>=disc[u]) ap[u]=true;
                }
            }
        }
    }
    
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int>disc(V);
        vector<int>low(V,INT_MAX);
        vector<bool>ap(V,false);
        
        for(int i=0;i<V;i++){
            if(vis.find(i)==vis.end()) dfs(i,adj,disc,low,ap,1,-1);
        }
        
        vector<int>ans;
        for(int i=0;i<V;i++) if(ap[i]) ans.push_back(i);
        if(ans.size()==0) return {-1};
        return ans;
        
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
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends