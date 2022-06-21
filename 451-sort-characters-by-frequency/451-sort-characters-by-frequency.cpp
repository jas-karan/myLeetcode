class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>map;
        for(char c:s) map[c]++;
        
        priority_queue<pair<int,int>>pq;
        
        for(auto e:map) pq.push({e.second,e.first});
        
        string ans="";
        
        while(!pq.empty()){
            int x = pq.top().first;
            int y = pq.top().second;
            pq.pop();
            
            while(x--) ans.push_back(y);
        }
        
        return ans;
    }
};