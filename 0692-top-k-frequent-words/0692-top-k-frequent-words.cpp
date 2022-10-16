class Solution {
public:
    struct comp{
      bool operator()(pair<int,string>&a,pair<int,string>&b){
          if(a.first==b.first) return a.second<b.second;
          return a.first>b.first;
      }  
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        unordered_map<string,int>mp;
        for(string s:words) mp[s]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp>pq;
        for(auto e:mp){
            pq.push({e.second,e.first});
            if(pq.size()>k) pq.pop();
        }
        while(pq.size()){
            ans.push_back({pq.top().second});
            pq.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};