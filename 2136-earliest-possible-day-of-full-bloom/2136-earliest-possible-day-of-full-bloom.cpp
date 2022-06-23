class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>v;
        for(int i=0;i<plantTime.size();i++){
            v.push_back({growTime[i], plantTime[i]});
        }
        
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        
        int res=0;
        int cur=0;
        for(auto p:v){
            res = max(res,cur+p.first+p.second);
            cur+=p.second;
        }
        
        return res;
        
    }
};