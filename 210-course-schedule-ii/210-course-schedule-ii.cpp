class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>>graph(n);
        vector<int>indeg(n,0);
        
        for(auto p:pre){
            graph[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        
        int cnt= 0;
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        
        vector<int>schedule;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            schedule.push_back(curr); 
            cnt++;
            
            for(int nbr:graph[curr]){
                indeg[nbr]--;
                if(indeg[nbr]==0) q.push(nbr);
            }
        }
        
        if(cnt!=n) return {};
        return schedule;
    }
};