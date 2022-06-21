class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>indeg(n,0);
        
        for(auto e:roads){
            indeg[e[0]]++;
            indeg[e[1]]++;
        }
        
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<n;i++) pq.push({indeg[i],i});
        
        unordered_map<int,int>map;
        
        int imp = n;
        while(!pq.empty()){
            map[pq.top().second]=imp;
            pq.pop();
            imp--;
        }
        
        long long res=0;
        
        for(auto e:roads){
            res+=(map[e[0]]+map[e[1]]);
        }
        
        return res;
    }
};