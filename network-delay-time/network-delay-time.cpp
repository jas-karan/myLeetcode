class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {    
        vector<vector<pair<int,int>>>graph(n);
        
        for(auto t:times){
            graph[t[0]-1].push_back({t[1]-1,t[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>d(n,INT_MAX);
        d[k-1]=0;
        pq.push({0,k-1});
        
        while(!pq.empty()){
            int curr = pq.top().second;
            pq.pop();
            
            for(auto p:graph[curr]){
                int nbr = p.first;
                int w = p.second;
                
                if(d[nbr]>w+d[curr]){
                    d[nbr]=w+d[curr];
                    pq.push({d[nbr],nbr});
                }
            }
        }
        
        int res=0;
        
        for(int i:d) res=max(i,res);
        
        return res==INT_MAX?-1:res;
    }
};