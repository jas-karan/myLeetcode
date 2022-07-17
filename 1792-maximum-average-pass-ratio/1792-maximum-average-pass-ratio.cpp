class comp{
    public:
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        double ad = double(a.first+1)/double(a.second+1) - double(a.first)/double(a.second);
        double bd = double(b.first+1)/double(b.second+1) - double(b.first)/double(b.second);
        return ad<bd;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int st) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        for(auto c:classes) pq.push({c[0],c[1]});
        
        while(st--){
            auto t=pq.top();
            pq.pop();
            
            pq.push({t.first+1,t.second+1});
        }
        
        double ans=0.0;
        while(!pq.empty()){
            auto t=pq.top(); pq.pop();
            ans+=double(t.first)/(double)t.second;
        }
        
        return ans/double(classes.size());
    }
};