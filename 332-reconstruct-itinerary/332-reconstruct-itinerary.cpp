class Solution {
public:
    unordered_map<string,priority_queue<string, vector<string>, greater<string>>>mp;
    vector<string>ans;
    
    void dfs(string src){
        
        while(mp[src].size()>0){
            string nbd = mp[src].top();
            mp[src].pop();
            dfs(nbd);
        }
        
        ans.push_back(src);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //every edge has to be visited exactly once
        //eulerian path
        //here vertex can be visited again if multiple paths from that vertex
        //so here we mark edges as visited or we can simply remove the edges
        
        for(auto t:tickets){
            mp[t[0]].push(t[1]);
        }
        
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};