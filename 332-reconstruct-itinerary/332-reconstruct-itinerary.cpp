class Solution {
public:
    //priority_queue<string,vector<string>,greater<string>> => min heap
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>>paths;
    
    vector<string>ans;
    void dfs(string from){
        while(paths[from].size()){
            string to = paths[from].top();
            paths[from].pop();
            dfs(to);
        }
        ans.push_back(from);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto t:tickets){
            paths[t[0]].push(t[1]);
        }
        
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};