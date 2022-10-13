class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char c:s) mp[c]++;
        priority_queue<pair<int,char>>pq;
        for(auto m:mp) pq.push({m.second,m.first});
        
        string res = "";
        while(pq.size()){
            auto t = pq.top(); pq.pop();
            while(t.first--) res+=t.second;
        }
        return res;
    }
};